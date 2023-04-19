#!/usr/bin/env python3

from sympy import *
import sys


class ElepticalArray:
    def __init__(self, indexes, negative=False):
        self.indexes = indexes
        self.negative = negative

    def __str__(self):
        return "ElepticalArray({},{})".format(self.indexes, "negative" if self.negative else "positive")

    def reorder_with_last(self, index, drop=False):
        return self.reorder_with_moving(index, len(self.indexes) - 1, drop)

    def reorder_with_first(self, index, drop=False):
        return self.reorder_with_moving(index, 0, drop)

    def reorder_with_moving(self, index, position, drop=False):
        if not index in self.indexes:
            raise Exception("Index not found")

        new_indexes = self.indexes.copy()
        new_indexes.remove(index)
        if not drop:
            new_indexes.insert(position, index)
        need_to_negate = (self.indexes.index(index) - position) % 2 == 1

        return ElepticalArray(new_indexes, not self.negative if need_to_negate else self.negative)

    def copy(self):
        return ElepticalArray(self.indexes.copy(), self.negative)

    def is_sorted(self):
        for i in range(len(self.indexes) - 1):
            if self.indexes[i] > self.indexes[i + 1]:
                return False
        return True

    def sorted(self):
        return self.sorted_as_template(sorted(self.indexes))

    def sorted_as_template(self, template):
        c = self.copy()
        sorted_indexes = template
        for idx in range(len(sorted_indexes)):
            c = c.reorder_with_moving(sorted_indexes[idx], idx)
        return c


class CliffordMulter:
    def __init__(self, eleptical_ones=[], dual_ones=[],  total_elipse=[], total_dual=[], negative=False, null=False):
        self.dual_ones = dual_ones
        self.eleptical_ones = ElepticalArray(eleptical_ones, negative)
        self.total_elipse = total_elipse
        self.total_dual = total_dual
        self.null = null

    def is_null(self):
        return self.null

    def sign(self):
        return -1 if self.eleptical_ones.negative else 1

    def grade(self):
        return len(self.dual_ones) + len(self.eleptical_ones.indexes)

    def antigrade(self):
        return len(self.total_elipse) + len(self.total_dual) - self.grade()

    def reverse(self):
        gr = self.grade()
        s = gr*(gr-1)/2
        sign = (-1)**s
        neg = sign == -1
        negative = neg != self.eleptical_ones.negative
        return CliffordMulter(self.eleptical_ones.indexes, self.dual_ones, self.total_elipse, self.total_dual, negative)

    # def left_complement(self):

    def prod(self, other):
        for x in self.dual_ones:
            for y in other.dual_ones:
                return CliffordMulter(null=True)

        dual_ones = self.dual_ones + other.dual_ones

        indexes_common = set(self.eleptical_ones.indexes).intersection(
            set(other.eleptical_ones.indexes))

        a_eleptical = self.eleptical_ones
        b_eleptical = other.eleptical_ones

        for x in indexes_common:
            a_eleptical = a_eleptical.reorder_with_last(x, drop=True)
            b_eleptical = b_eleptical.reorder_with_first(x, drop=True)

        eleptical_ones = a_eleptical.indexes + b_eleptical.indexes
        negative = a_eleptical.negative != b_eleptical.negative

        eleptical_array = ElepticalArray(eleptical_ones, negative)
        eleptical_array = eleptical_array.sorted()
        eleptical_array_as_tuple = tuple(eleptical_array.indexes)
        canonical_form = CliffordAlgebra.canonical_formes[eleptical_array_as_tuple]
        eleptical_array = eleptical_array.sorted_as_template(canonical_form)

        return CliffordMulter(eleptical_array.indexes, dual_ones, self.total_elipse, self.total_dual, negative=eleptical_array.negative)

    def antiprod(self, other):
        return self.prod(other).reverse()

    def __str__(self):
        if len(self.dual_ones) == 0 and len(self.eleptical_ones.indexes) == 0:
            return "e"

        es = "".join(f"{i}" for i in self.eleptical_ones.indexes)
        base = "e_"
        ds = "".join(f"{i}" for i in self.dual_ones)

        sign = "-" if self.eleptical_ones.negative else ""
        return sign+base + ds + es

    def __repr__(self):
        return self.__str__()

    def symbol_name(self):
        if len(self.dual_ones) == 0 and len(self.eleptical_ones.indexes) == 0:
            return "e"

        es = "".join(f"{i}" for i in self.eleptical_ones.indexes)
        base = "e_"
        ds = "".join(f"{i}" for i in self.dual_ones)

        return base + ds + es

    def symbol(self):
        a = self.symbol_name()
        sign = -1 if self.eleptical_ones.negative else +1
        return CliffordAlgebra.canonical_symbols[f"{a}"] * sign


class CliffordGeometrySymbol(Symbol):
    def __new__(cls, name, *args, **kwargs):
        return super().__new__(cls, name, commutative=False)

    def __init__(self, name, ellipse, dual, total_elipse, total_dual, negative=False):
        super().__init__()
        self.multer = CliffordMulter(
            ellipse, dual,  total_elipse, total_dual, negative)

    @staticmethod
    def from_multer(multer, eones, dones):
        return multer.symbol()

    def __mul__(self, other):
        if isinstance(other, CliffordGeometrySymbol):
            multer = self.multer.prod(other.multer)
            return multer.symbol()
        else:
            return super().__mul__(other)

    def __pow__(self, power, modulo=None):
        if power == 2:
            return self * self
        else:
            raise Exception("Not implemented")


class CliffordAlgebra:
    eleptical_ones = [1, 2, 3]
    dual_ones = []
    e = CliffordGeometrySymbol("e", [], [], eleptical_ones, dual_ones)
    e_1 = CliffordGeometrySymbol("e_1", [1], [], eleptical_ones, dual_ones)
    e_2 = CliffordGeometrySymbol("e_2", [2], [], eleptical_ones, dual_ones)
    e_3 = CliffordGeometrySymbol("e_3", [3], [], eleptical_ones, dual_ones)
    e_23 = CliffordGeometrySymbol(
        "e_23", [2, 3], [], eleptical_ones, dual_ones)
    e_31 = CliffordGeometrySymbol(
        "e_31", [3, 1], [], eleptical_ones, dual_ones)
    e_12 = CliffordGeometrySymbol(
        "e_12", [1, 2], [], eleptical_ones, dual_ones)
    e_321 = CliffordGeometrySymbol(
        "e_321", [3, 2, 1], [], eleptical_ones, dual_ones)

    canonical_formes = {
        (1, 2, 3): (3, 2, 1),
        (2, 3): (2, 3),
        (1, 3): (3, 1),
        (1, 2): (1, 2),
        (1,): (1,),
        (2,): (2,),
        (3,): (3,),
        (): ()
    }

    canonical_symbols = {
        "e_321": e_321,
        "e_23": e_23,
        "e_12": e_12,
        "e_31": e_31,
        "e_1": e_1,
        "e_2": e_2,
        "e_3": e_3,
        "e": e
    }


class CliffordAlgebra301:
    eleptical_ones = [1, 2, 3]
    dual_ones = [4]
    e = CliffordGeometrySymbol("e", [], [], eleptical_ones, dual_ones)
    e_1 = CliffordGeometrySymbol("e_1", [1], [], eleptical_ones, dual_ones)
    e_2 = CliffordGeometrySymbol("e_2", [2], [], eleptical_ones, dual_ones)
    e_3 = CliffordGeometrySymbol("e_3", [3], [], eleptical_ones, dual_ones)
    e_4 = CliffordGeometrySymbol("e_4", [], [4], eleptical_ones, dual_ones)
    e_23 = CliffordGeometrySymbol(
        "e_23", [2, 3], [], eleptical_ones, dual_ones)
    e_31 = CliffordGeometrySymbol(
        "e_31", [3, 1], [], eleptical_ones, dual_ones)
    e_12 = CliffordGeometrySymbol(
        "e_12", [1, 2], [], eleptical_ones, dual_ones)

    e_41 = CliffordGeometrySymbol("e_41", [1], [4], eleptical_ones, dual_ones)
    e_42 = CliffordGeometrySymbol("e_42", [2], [4], eleptical_ones, dual_ones)
    e_43 = CliffordGeometrySymbol("e_43", [3], [4], eleptical_ones, dual_ones)

    e_321 = CliffordGeometrySymbol(
        "e_321", [3, 2, 1], [], eleptical_ones, dual_ones)

    e_423 = CliffordGeometrySymbol(
        "e_423", [2, 3], [4], eleptical_ones, dual_ones)
    e_431 = CliffordGeometrySymbol(
        "e_431", [3, 1], [4], eleptical_ones, dual_ones)
    e_412 = CliffordGeometrySymbol(
        "e_412", [1, 2], [4], eleptical_ones, dual_ones)

    e_4321 = CliffordGeometrySymbol(
        "e_4321", [3, 2, 1], [4], eleptical_ones, dual_ones)

    canonical_formes = {
        (1, 2, 3): (3, 2, 1),
        (2, 3): (2, 3),
        (1, 3): (3, 1),
        (1, 2): (1, 2),
        (1,): (1,),
        (2,): (2,),
        (3,): (3,),
        (): ()
    }

    # canonical_symbols = {
    #     "e_321": e_321,
    #     "e_23": e_23,
    #     "e_12": e_12,
    #     "e_31": e_31,
    #     "e_1": e_1,
    #     "e_2": e_2,
    #     "e_3": e_3,
    #     "e": e
    # }


alphabet = [
    CliffordMulter([]),
    CliffordMulter([1]),
    CliffordMulter([2]),
    CliffordMulter([3]),
    CliffordMulter([2, 3]),
    CliffordMulter([3, 1]),
    CliffordMulter([1, 2]),
    CliffordMulter([3, 2, 1])
]

var("a_23, a_31, a_12, b_23, b_31, b_12")

e = CliffordAlgebra.e
e_1 = CliffordAlgebra.e_1
e_2 = CliffordAlgebra.e_2
e_3 = CliffordAlgebra.e_3
e_23 = CliffordAlgebra.e_23
e_31 = CliffordAlgebra.e_31
e_12 = CliffordAlgebra.e_12
e_321 = CliffordAlgebra.e_321

earr = [e, e_1, e_2, e_3, e_23, e_31, e_12,   e_321]
marr = [e.multer, e_1.multer, e_2.multer, e_3.multer,
        e_23.multer, e_31.multer,  e_12.multer,  e_321.multer]

e = CliffordAlgebra301.e
e_1 = CliffordAlgebra301.e_1
e_2 = CliffordAlgebra301.e_2
e_3 = CliffordAlgebra301.e_3
e_4 = CliffordAlgebra301.e_4
e_23 = CliffordAlgebra301.e_23
e_31 = CliffordAlgebra301.e_31
e_12 = CliffordAlgebra301.e_12
e_41 = CliffordAlgebra301.e_41
e_42 = CliffordAlgebra301.e_42
e_43 = CliffordAlgebra301.e_43
e_321 = CliffordAlgebra301.e_321
e_423 = CliffordAlgebra301.e_423
e_431 = CliffordAlgebra301.e_431
e_412 = CliffordAlgebra301.e_412
e_4321 = CliffordAlgebra301.e_4321

marr2 = [e.multer, e_1.multer, e_2.multer, e_3.multer, e_4.multer,
         e_23.multer, e_31.multer,  e_12.multer, e_41.multer, e_42.multer, e_43.multer,
         e_321.multer, e_423.multer, e_431.multer, e_412.multer, e_4321.multer]


def print_binary_operation_table(f, arr):
    L = 8
    sys.stdout.write(L*" ")
    for a in arr:
        s = str(a)
        s = s + " " * (L - len(s))
        sys.stdout.write(s)
    sys.stdout.write("\r\n")

    for a in arr:
        s = str(a)
        s = s + " " * (L - len(s))
        sys.stdout.write(s)
        for b in arr:
            s = str(f(a, b))
            s = s + " " * (L - len(s))
            sys.stdout.write(s)
        sys.stdout.write("\r\n")


def print_unary_operation_table(f, arr):
    L = 8
    sys.stdout.write(L*" ")
    for a in arr:
        s = str(a)
        s = s + " " * (L - len(s))
        sys.stdout.write(s)
    sys.stdout.write("\r\n")

    sys.stdout.write(L*" ")
    for a in arr:
        s = str(f(a))
        s = s + " " * (L - len(s))
        sys.stdout.write(s)

    sys.stdout.write("\r\n")


def grade(x):
    return x.grade()


def antigrade(x):
    return x.antigrade()


def reverse(x):
    return x.reverse()


def prod(x, y):
    return x.prod(y)


def antiprod(x, y):
    return x.antiprod(y)


print()
print_unary_operation_table(lambda x: grade(x), marr)

print()
print_unary_operation_table(lambda x: antigrade(x), marr)

print()
print_unary_operation_table(lambda x: reverse(x), marr)

print()
print_binary_operation_table(lambda x, y: prod(x, y), marr)

print()
print_binary_operation_table(lambda x, y: antiprod(x, y), marr)


def collect_results_of_binary_operation(f, arr):
    dct = {}
    for a in arr:
        dct[a.symbol_name()] = []

    for a in arr:
        for b in arr:
            res = f(a, b)
            if res.is_null():
                continue
            sign = res.sign()
            dct[res.symbol_name()].append((a, b, sign))

    return dct


def make_binary_function(f, name, type, arr):
    dct = collect_results_of_binary_operation(lambda x, y: prod(x, y), arr)
    s = ""
    s += f"{type} {name}({type} a, {type} b) {{\r\n"
    for k, v in dct.items():
        s += f"    auto {k} = "
        sss = []
        for a, b, sign in v:
            l = ""
            if sign == -1:
                l += "-"
            l += f"a.{a.symbol_name()}*b.{b.symbol_name()}"
            sss.append(l)
        s += " + ".join(sss)
        s += "; \r\n"
    sss = ", ".join(dct.keys())
    s += f"    return {{{sss}}};\r\n"
    s += "}"
    return s


s = make_binary_function(lambda x, y: prod(
    x, y), "prod", "maho::multivector300", marr)
print(s)

print()
s = make_binary_function(lambda x, y: prod(
    x, y), "prod", "maho::multivector301", marr2)
print(s)

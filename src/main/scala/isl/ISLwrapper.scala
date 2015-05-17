package isl

object Implicits {
  implicit class Pointer(val ptr: Long)
  implicit def deref(p: Pointer): Long = p.ptr
}

private[isl] class ISL {
  // context
  @native def createContext: Long
  @native def releaseContext(ctx: Long): Unit

  // values
    // creation
  @native def valZero(ctx: Long): Long
  @native def valOne(ctx: Long): Long
  @native def valNegOne(ctx: Long): Long
  @native def valNan(ctx: Long): Long
  @native def valInfty(ctx: Long): Long
  @native def valNegInfty(ctx: Long): Long

    // queries
  @native def valIsZero(value: Long): Boolean
  @native def valIsOne(value: Long): Boolean
  @native def valIsNegOne(value: Long): Boolean
  @native def valIsNan(value: Long): Boolean
  @native def valIsInfty(value: Long): Boolean
  @native def valIsNegInfty(value: Long): Boolean

    // binary properties defined on pairs of values
  @native def valLT(v1: Long, v2: Long): Boolean
  @native def valLE(v1: Long, v2: Long): Boolean
  @native def valGT(v1: Long, v2: Long): Boolean
  @native def valGE(v1: Long, v2: Long): Boolean
  @native def valEQ(v1: Long, v2: Long): Boolean
  @native def valNE(v1: Long, v2: Long): Boolean

    // unary operations
  @native def valAbs(value: Long): Long
  @native def valNeg(value: Long): Long
  @native def valFloor(value: Long): Long
  @native def valCeil(value: Long): Long
  @native def valTrunc(value: Long): Long
  @native def val2Exp(value: Long): Long

    // binary operations
  @native def valMin(v1: Long, v2: Long): Long
  @native def valMax(v1: Long, v2: Long): Long
  @native def valAdd(v1: Long, v2: Long): Long
  @native def valSub(v1: Long, v2: Long): Long
  @native def valMul(v1: Long, v2: Long): Long
  @native def valDiv(v1: Long, v2: Long): Long

    // printer for values
  @native def printVal(value: Long): String

  // ids
  @native def idAlloc(ctx: Long, name: String, user: Long): Long

  // spaces
  @native def spaceAlloc(ctx: Long, nparam: Int, n_in: Int, n_out: Int): Long

  // local spaces
  @native def basicSetGetLocalSpace(set: Long): Long

  // basic sets
  @native def basicSetEmpty(space: Long): Long
}

// a singleton for keeping a single instance and context
object ISL {
  System.loadLibrary("isl_jni")
  val isl = new ISL
  val ctx = isl.createContext
}

private[isl] trait ISL_value_iface {

  def zero:     ISL_value
  def one:      ISL_value
  def negOne:   ISL_value
  def nan:      ISL_value
  def infty:    ISL_value
  def negInfty: ISL_value

  def isZero      (that: ISL_value): Boolean
  def isOne       (that: ISL_value): Boolean
  def isNegOne    (that: ISL_value): Boolean
  def isNan       (that: ISL_value): Boolean
  def isInfty     (that: ISL_value): Boolean
  def isNegInfty  (that: ISL_value): Boolean

  def <      (that: ISL_value): Boolean
  def <=     (that: ISL_value): Boolean
  def >      (that: ISL_value): Boolean
  def >=     (that: ISL_value): Boolean
  def ==     (that: ISL_value): Boolean
  def !=     (that: ISL_value): Boolean
  
  def abs: ISL_value
  def neg: ISL_value

  def +      (that: ISL_value): ISL_value
  def -      (that: ISL_value): ISL_value
  def *      (that: ISL_value): ISL_value
  def /      (that: ISL_value): ISL_value
}

import Implicits._
case class ISL_value(value: Pointer = Pointer(0L)) extends ISL_value_iface {

  private val isl = ISL.isl
  private val ctx = ISL.ctx

  implicit def make(p: Long) = new ISL_value(p)

  def zero     = isl.valZero     (ctx)
  def one      = isl.valOne      (ctx)
  def negOne   = isl.valNegOne   (ctx)
  def nan      = isl.valNan      (ctx)
  def infty    = isl.valInfty    (ctx)
  def negInfty = isl.valNegInfty (ctx)

  def isZero      (that: ISL_value): Boolean = isl.valIsZero     (that.value)
  def isOne       (that: ISL_value): Boolean = isl.valIsOne      (that.value)
  def isNegOne    (that: ISL_value): Boolean = isl.valIsNegOne   (that.value)
  def isNan       (that: ISL_value): Boolean = isl.valIsNan      (that.value)
  def isInfty     (that: ISL_value): Boolean = isl.valIsInfty    (that.value)
  def isNegInfty  (that: ISL_value): Boolean = isl.valIsNegInfty (that.value)

  def <      (that: ISL_value): Boolean = isl.valLT(value, that.value)
  def <=     (that: ISL_value): Boolean = isl.valLE(value, that.value)
  def >      (that: ISL_value): Boolean = isl.valGT(value, that.value)
  def >=     (that: ISL_value): Boolean = isl.valGE(value, that.value)
  def ==     (that: ISL_value): Boolean = isl.valEQ(value, that.value)
  def !=     (that: ISL_value): Boolean = isl.valNE(value, that.value)

  def abs: ISL_value = ISL_value(isl.valAbs(value))
  def neg: ISL_value = ISL_value(isl.valNeg(value))

  def +      (that: ISL_value): ISL_value = isl.valAdd(value, that.value)
  def -      (that: ISL_value): ISL_value = isl.valSub(value, that.value)
  def *      (that: ISL_value): ISL_value = isl.valMul(value, that.value)
  def /      (that: ISL_value): ISL_value = isl.valDiv(value, that.value)

  override def toString = isl.printVal(value)
}

private[isl] trait ISL_id_iface {
  def idAlloc(name: String, user: Pointer): ISL_id
}

case class ISL_id(value: Pointer = Pointer(0L)) extends ISL_basic_set_iface {
  private val isl = ISL.isl
  private val ctx = ISL.ctx

  implicit def make(p: Long) = new ISL_id(p)

  def idAlloc(name: String, user: Pointer) = isl.idAlloc(ctx, name, user)
}

private[isl] trait ISL_basic_set_iface {
  // TODO: def empty: ISL_basic_set
}

case class ISL_basic_set(value: Pointer = Pointer(0L)) extends ISL_basic_set_iface {
}

// --- Code in App body will get wrapped in a main method on compilation
object ISL_sample extends App {

  // do something useful
  val isl_value = ISL_value()
  val zero = isl_value.zero
  val one = isl_value.one
  println("zero is zero? " + isl_value.isZero(zero) + " one is zero? " + isl_value.isZero(one))

  val neg_one = isl_value.negOne
  val infty = isl_value.infty
  val neg_infty = isl_value.negInfty
  val nan = isl_value.nan

  println("-1 < 1 ? " + (neg_one < one) + " -1 == 1 ? " + (neg_one == one) + " infty == infty ? " + (infty == infty)
    + " infty == nan ? " + (infty == nan) + " nan == nan ??? " + (nan == nan))

  println("printing infty & nan: infty: " + infty + " neg_infty: " + neg_infty + " nan: " + nan)

  println("printing values: neg_one: " + neg_one + " one: " + one + " zero: " + zero)

  // println("checking unary & binary ops: -1 + 1 == 0 ? " + (neg_one + one == zero) + " abs(-1) == 1 ? " + (neg_one.abs == one))
  println("checking unary & binary ops: -1 + 1: " + (neg_one + one))
  println("printing values: neg_one: " + neg_one + " one: " + one + " zero: " + zero)
  println("checking unary & binary ops: abs(-1) == 1 ? " + (neg_one.abs == one))
  println("printing values: neg_one: " + neg_one + " one: " + one + " zero: " + zero)
  println("checking unary & binary ops: abs(-1) == 1 ? " + ((neg_one.abs) == one))
  println("printing values: neg_one: " + neg_one + " one: " + one + " zero: " + zero)
}

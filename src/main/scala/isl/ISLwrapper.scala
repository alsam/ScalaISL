package isl

case class Pointer(ptr: Long)

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
}

// a singleton for keeping a single instance and context
object ISL {
  System.loadLibrary("isl_jni")
  val isl = new ISL
  val ctx = isl.createContext
}

case class ISL_context(ctx: Pointer)

private[isl] trait ISL_value_iface {

  def zero:     ISL_value
  def one:      ISL_value
  def negOne:   ISL_value
  def nan:      ISL_value
  def infty:    ISL_value
  def negInfty: ISL_value

  def isZero (that: ISL_value): Boolean
  def isOne  (that: ISL_value): Boolean

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

case class ISL_value(value: Pointer = Pointer(0L)) extends ISL_value_iface {
  private val isl = ISL.isl
  private val ctx = ISL.ctx

  def zero     = ISL_value( Pointer(isl.valZero     (ctx)))
  def one      = ISL_value( Pointer(isl.valOne      (ctx)))
  def negOne   = ISL_value( Pointer(isl.valNegOne   (ctx)))
  def nan      = ISL_value( Pointer(isl.valNan      (ctx)))
  def infty    = ISL_value( Pointer(isl.valInfty    (ctx)))
  def negInfty = ISL_value( Pointer(isl.valNegInfty (ctx)))

  def isZero (that: ISL_value): Boolean = isl.valIsZero (that.value.ptr)
  def isOne  (that: ISL_value): Boolean = isl.valIsOne  (that.value.ptr)

  def <      (that: ISL_value): Boolean = isl.valLT(value.ptr, that.value.ptr)
  def <=     (that: ISL_value): Boolean = isl.valLE(value.ptr, that.value.ptr)
  def >      (that: ISL_value): Boolean = isl.valGT(value.ptr, that.value.ptr)
  def >=     (that: ISL_value): Boolean = isl.valGE(value.ptr, that.value.ptr)
  def ==     (that: ISL_value): Boolean = isl.valEQ(value.ptr, that.value.ptr)
  def !=     (that: ISL_value): Boolean = isl.valNE(value.ptr, that.value.ptr)

  def abs: ISL_value = ISL_value( Pointer(isl.valAbs(value.ptr)))
  def neg: ISL_value = ISL_value( Pointer(isl.valNeg(value.ptr)))

  def +      (that: ISL_value): ISL_value = ISL_value( Pointer(isl.valAdd(value.ptr, that.value.ptr)))
  def -      (that: ISL_value): ISL_value = ISL_value( Pointer(isl.valSub(value.ptr, that.value.ptr)))
  def *      (that: ISL_value): ISL_value = ISL_value( Pointer(isl.valMul(value.ptr, that.value.ptr)))
  def /      (that: ISL_value): ISL_value = ISL_value( Pointer(isl.valDiv(value.ptr, that.value.ptr)))

  override def toString = isl.printVal(value.ptr)
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
  val nan = isl_value.nan

  println("-1 < 1 ? " + (neg_one < one) + " -1 == 1 ? " + (neg_one == one) + " infty == infty ? " + (infty == infty)
    + " infty == nan ? " + (infty == nan) + " nan == nan ??? " + (nan == nan))

  println("printing values: -1: " + neg_one + " one: " + one + " zero: " + zero)

  //println("checking unary & binary ops: -1 + 1 == 0 ? " + (neg_one + one == zero) + " abs(-1) == 1 ? " + (neg_one.abs == one))
  println("checking unary & binary ops: abs(-1) == 1 ? " + (neg_one.abs == one))
}

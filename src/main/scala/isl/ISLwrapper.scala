package isl

case class Pointer(ptr: Long)

//def deref(p: Pointer) = p.ptr

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

  def isZero (other: ISL_value): Boolean
  def isOne  (other: ISL_value): Boolean

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

  def isZero (other: ISL_value): Boolean = isl.valIsZero (other.value.ptr)
  def isOne  (other: ISL_value): Boolean = isl.valIsOne  (other.value.ptr)
}

// --- Code in App body will get wrapped in a main method on compilation
object ISL_sample extends App {

  // do something useful
  val isl_value = ISL_value()
  val zero = isl_value.zero
  println("val is zero? " + isl_value.isZero(zero))

  val neg_one = isl_value.negOne
  val nan = isl_value.infty
}

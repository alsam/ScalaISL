package isl

class ISL {
  // context
  @native def createContext: Long
  @native def releaseContext(ctx: Long): Unit

  // values
  @native def valZero(ctx: Long): Long
  @native def valOne(ctx: Long): Long
  @native def valNegOne(ctx: Long): Long
  @native def valNan(ctx: Long): Long
  @native def valInfty(ctx: Long): Long
  @native def valNegInfty(ctx: Long): Long

  @native def valIsZero(value: Long): Boolean

}

// --- Code in App body will get wrapped in a main method on compilation
object ISL extends App {
  // --- Main method to test native library
  System.loadLibrary("isl_jni")
  val isl = new ISL
  private val ctx = isl.createContext

  // do something useful
  val zero = isl.valZero(ctx)
  println("val is zero? " + isl.valIsZero(zero))


  isl.releaseContext(ctx)
}


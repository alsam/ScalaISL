import org.scalatest.FunSuite
import isl._

class ValuesSuite extends FunSuite {

  private val isl_value = Value()

  test("val: `zero`, `negOne`, and `one`") {
    val zero = isl_value.zero
    val one = isl_value.one
    val neg_one = isl_value.negOne
    assert(isl_value.isZero(zero) && !isl_value.isZero(one))
    assert(isl_value.isZero(zero * neg_one))
    assert(isl_value.isOne(zero + one))
  }

  test("val: `infty`, `negInfty`, and `nan`") {
    val one = isl_value.one
    val zero = isl_value.zero
    val neg_infty = isl_value.negInfty
    val infty = isl_value.infty
    val nan = isl_value.nan
    assert(!(nan == nan) && !(nan != nan)) // the property of NANs
    assert(isl_value.isNan(infty * zero))
    assert(isl_value.isNan(neg_infty + infty))
    assert(isl_value.isNan(one / zero)) // ???
    assert(!isl_value.isInfty(one / zero)) // ???
  }

  test("id: `getName`") {
    val id = Identifier()
    val name = "ida"
    val ida = id.idAlloc(name, 0L)
    assert(ida.getName == name)
  }
}

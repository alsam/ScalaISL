package isl

import org.scalatest.FunSuite

class IdentifiersSuite extends FunSuite {

  test("id: `getName`") {
    val id = Identifier()
    val name = "ida"
    val ida = id.idAlloc(name, 0L)
    assert(ida.getName == name)
  }
}

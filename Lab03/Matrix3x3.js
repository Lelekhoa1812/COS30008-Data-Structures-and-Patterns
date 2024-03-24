/*

  Simple 3x3 Matrix class

*/

class Matrix3x3
{
  static create()
  {
    return new Matrix3x3();
  }

  constructor()
  {
    this.m11 = 1.0;
    this.m12 = 0.0;
    this.m13 = 0.0;
    this.m21 = 0.0;
    this.m22 = 1.0;
    this.m23 = 0.0;
    this.m31 = 0.0;
    this.m32 = 0.0;
    this.m33 = 1.0;
  }

  static getScaleMatrix(sx, sy)
  {
    var m = new Matrix3x3();

    m.m11 = sx;
    m.m22 = sy;

    return m;
  }

  static getRotationMatrix(angle)
  {
    var m = new Matrix3x3(),
	    theta = angle * Math.PI / 180.0,
	    sinTheta = Math.sin(theta),
	    cosTheta = Math.cos(theta)

    m.m11 = cosTheta;
    m.m21 = sinTheta;
    m.m12 = -sinTheta;
    m.m22 = cosTheta;

    return m;
  }

  static getTranslationMatrix(dx, dy)
  {
    var m = new Matrix3x3();

    m.m13 = dx;
    m.m23 = dy;

    return m;
  }

  multiplyByVector2D(v)
  {
    // Vector2D has no 3rd component (assume 1)

    var x = v.x * this.m11 + v.y * this.m12 + this.m13,
        y = v.x * this.m21 + v.y * this.m22 + this.m23,
        w = v.x * this.m31 + v.y * this.m32 + this.m33;

    // w should never be 0.
    return Vector2D.create(x/w, y/w);
  }

  multiplyByMatrix3x3(mat)
  {
    var m = new Matrix3x3();

    m.m11 = this.m11 * mat.m11 + this.m12 * mat.m21 + this.m13 * mat.m31;
    m.m12 = this.m11 * mat.m12 + this.m12 * mat.m22 + this.m13 * mat.m32;
    m.m13 = this.m11 * mat.m13 + this.m12 * mat.m23 + this.m13 * mat.m33;

    m.m21 = this.m21 * mat.m11 + this.m22 * mat.m21 + this.m23 * mat.m31;
    m.m22 = this.m21 * mat.m12 + this.m22 * mat.m22 + this.m23 * mat.m32;
    m.m23 = this.m21 * mat.m13 + this.m22 * mat.m23 + this.m23 * mat.m33;

    m.m31 = this.m31 * mat.m11 + this.m32 * mat.m21 + this.m33 * mat.m31;
    m.m32 = this.m31 * mat.m12 + this.m32 * mat.m22 + this.m33 * mat.m32;
    m.m33 = this.m31 * mat.m13 + this.m32 * mat.m23 + this.m33 * mat.m33;

    return m;
  }

  toString()
  {
    var row1 = this.m11.toString() + "\t" +
               this.m12.toString() + "\t" +
               this.m13.toString(),
        row2 = this.m21.toString() + "\t" +
               this.m22.toString() + "\t" +
               this.m23.toString(),
        row3 = this.m31.toString() + "\t" +
               this.m32.toString() + "\t" +
               this.m33.toString();

    return row1 + "\n" + row2 + "\n" + row3;
  }
}

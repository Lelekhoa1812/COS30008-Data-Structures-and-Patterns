/*

  Simple functional 2D Vector class

*/

class Vector2D
{
  static create(aX = 0.0, aY = 0.0)
  {
    var v = new Vector2D(aX, aY);

    return v;
  }
	
  constructor(x, y, id = "")
  {
    this._x = x;
    this._y = y;
	this._id = this.toString();
	this.color = "blue";
  }

  get x()
  {
    return this._x;
  }

  get y()
  {
    return this._y;
  }

  get id()
  {
    return this._id;
  }

  add(other)
  {
    return new Vector2D(this.x + other.x, this.y + other.y);
  }

  subtract(other)
  {
    return new Vector2D(this.x - other.x, this.y - other.y);
  }

  multiply(scalar)
  {
    return new Vector2D(this.x * scalar, this.y * scalar);
  }

  dot(other)
  {
    return this.x * other.x + this.y * other.y;
  }

  cross(other)
  {
    return this.x * other.y - this.y * other.x
  }

  length()
  {
    var val = Math.sqrt(this.x * this.x + this.y * this.y);

    return Math.round(val * 100) / 100.0;
  }

  normalize()
  {
    return this.divide( this.length() );
  }

  direction()
  {
    var val = Math.atan2( this.y, this.x ) * 180.0 / Math.PI;

    return Math.round(val * 100) / 100.0;
  }

  align(angle)
  {
      var radians = angle * Math.PI / 180.0,
          vector = new Vector2D(Math.cos(radians), Math.sin(radians));

      return vector.multiply( this.length() );
  }

  toString()
  {
    return "[" + (Math.round( this.x * 1000.0 ) / 1000.0) + "," + (Math.round( this.y * 1000.0 ) / 1000.0) + "]"
  }

  draw(context, pM)
  {
    // translate coordinates
    var loc = pM.multiplyByVector2D(this);

    context.beginPath();
    context.fillStyle = this.color;
    context.arc(loc.x, loc.y, 5, 0, Math.PI * 2, false);
    context.fill();

    context.font = "16px Verdana";
    context.fillText(this.id, loc.x, loc.y + 15)
  }
}

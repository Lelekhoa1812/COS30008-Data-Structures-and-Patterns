
// T-Rex - Vector2D and Polygon

window.onload = function()
{
	var canvas = document.getElementById("canvas"),
     	context = canvas.getContext("2d"),
      	width = canvas.width = window.innerWidth,
      	height = canvas.height = window.innerHeight,
    	sM = Matrix3x3.getScaleMatrix(50, -50),
    	tM = Matrix3x3.getTranslationMatrix(width/100, height/-100),
		rotation = 0,
	    step = 0,
		rM = Matrix3x3.getRotationMatrix(rotation),
		pM = sM.multiplyByMatrix3x3(tM.multiplyByMatrix3x3(rM)),
	    center = Vector2D.create(0.0, 0.0);
		centerLoc = pM.multiplyByVector2D(center),
	  	vertices = [];

	// data
	vertices.push( Vector2D.create( 6, 4 ) );
	vertices.push( Vector2D.create( 3, 1 ) );
	vertices.push( Vector2D.create( 1, 2 ) );
	vertices.push( Vector2D.create( -1, 5 ) );
	vertices.push( Vector2D.create( -2, 5 ) );
	vertices.push( Vector2D.create( -3, 4 ) );
	vertices.push( Vector2D.create( -4, 4 ) );
	vertices.push( Vector2D.create( -5, 3 ) );
	vertices.push( Vector2D.create( -5, 2 ) );
	vertices.push( Vector2D.create( -2, 2 ) );
	vertices.push( Vector2D.create( -5, 1 ) );
	vertices.push( Vector2D.create( -4, 0 ) );
	vertices.push( Vector2D.create( -2, 1 ) );
	vertices.push( Vector2D.create( -1, 0 ) );
	vertices.push( Vector2D.create( 0, -3 ) );
	vertices.push( Vector2D.create( -1, -4 ) );
	vertices.push( Vector2D.create( 1, -4 ) );
	vertices.push( Vector2D.create( 2, -3 ) );
	vertices.push( Vector2D.create( 1, -2 ) );
	vertices.push( Vector2D.create( 3, -1 ) );
	vertices.push( Vector2D.create( 5, 1 ) );

  draw();

  document.body.addEventListener("keyup", function(event)
  {
    console.log(event.keyCode);

    switch (event.keyCode)
    {
      case 37:  // left
        rotation = rotation + step;
		rM = Matrix3x3.getRotationMatrix(rotation);
		pM = sM.multiplyByMatrix3x3(tM.multiplyByMatrix3x3(rM));
        break;

      case 38:  // up
		step++;
        break;

      case 40:  // down
        step--;
        break;

      case 39:  // right
		rotation = rotation - step;
		rM = Matrix3x3.getRotationMatrix(rotation);
		pM = sM.multiplyByMatrix3x3(tM.multiplyByMatrix3x3(rM));
        break;

      default:
        break;
    }
  })

  document.body.addEventListener("mousemove", function(event)
  {
	  rotation = (event.clientX * -3600.0) / width;
	  rM = Matrix3x3.getRotationMatrix(rotation);
	  pM = sM.multiplyByMatrix3x3(tM.multiplyByMatrix3x3(rM));
  })

  function drawXY()
  {
    context.beginPath();
    context.strokeStyle = "gray";
    context.setLineDash([]);
    context.lineWidth = 3;
    context.moveTo(20, height/2);
    context.lineTo(width-20, height/2);
    context.moveTo(centerLoc.x, 20);
    context.lineTo(centerLoc.x, height-20);
    context.stroke();

    context.font = "30px Verdana";
    context.fillStyle = "gray";
    context.fillText("x", centerLoc.x - 30, 40)
    context.fillText("y", width - 40, centerLoc.y + 30)
  }

  function drawSegments(context, pM)
  {
	  for(var i = 1; i < this.vertices.length; i++)
	  {
		  var v1 = this.vertices[i],
		  	  v0 = this.vertices[i-1],
		      v1Loc = pM.multiplyByVector2D(v1),
		      v0Loc = pM.multiplyByVector2D(v0);

		  context.beginPath();
		  context.strokeStyle = "green";
		  context.lineWidth = 1;
		  context.moveTo(v0Loc.x, v0Loc.y);
		  context.lineTo(v1Loc.x, v1Loc.y);
		  context.stroke();
	  }

  	var v1 = this.vertices[0],
  	  	v0 = this.vertices[this.vertices.length-1],
      	v1Loc = pM.multiplyByVector2D(v1),
      	v0Loc = pM.multiplyByVector2D(v0);

  	context.beginPath();
  	context.strokeStyle = "green";
  	context.lineWidth = 1;
  	context.moveTo(v0Loc.x, v0Loc.y);
  	context.lineTo(v1Loc.x, v1Loc.y);
  	context.stroke();
  }
  
  function drawVertices(context, pM)
  {
	  for(var i = 0; i < this.vertices.length; i++)
	  {
	      this.vertices[i].draw(context, pM);
	  }
  }

  function draw()
  {
    context.clearRect(0, 0, width, height);

	drawXY();
	drawSegments(context, pM);
	drawVertices(context, pM);
	
	requestAnimationFrame(draw);
  }
}

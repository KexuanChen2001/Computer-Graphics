//Oliver, 1930026012
//2022-4-6

0. There is whole code folder which can be run, and executable file is in "whole code\Assign0\Assign0.exe"
1. Components
This robot has two cylinder-like legs, two cylinder-like arms, spheres head and a cylinder body.
2. Movements
This robot can walk by switching the legs, and swing arms at the same time. Simulate running process.
3. Light
Point light and the reflection is added, could move with the robot.

4. How did the code changed?

(1).	Changed the function of cylinder in the geometry3 file. 
	Do the principle method learned from the TA course.
------------------void buildCylindersdata()-------------------------
	xy = radius * cosf(stackAngle); 			// r * cos(u)
	z = radius * tanf(stackAngle);
	x = xy * sinf(sectorAngle);            // r * sin(v)
	y = xy * cosf(sectorAngle);            // r * cos(v)
	//  k1--k1+1
	//  |  / |
	//  | /  |
	// special treatment to draw the top and bottom surface
	if (i == 0) {
		cylinderIndices.push_back(k1);cylinderIndices.push_back(top_pt);cylinderIndices.push_back(k1 + 1);
	}
	if (i+1 == stacks) {
		cylinderIndices.push_back(k2);cylinderIndices.push_back(bottom_pt);cylinderIndices.push_back(k2 + 1);
	}
------------------void initCylinder()-------------------------
change some contents, similar to sphere
------------------void drawcylinder()-------------------------
change some contents, similar to sphere

(2).	Draw the components

	Use pushMatrix() and popMatrix() every time when change the coordinates
	drawcylinder();
	drawsphere();
	adjust the parameters and put the components in proper positions.

(3).	Changed the robotAnimation()

	Adjust the animation and make the action smooth.
	Detailed codes on animation:
	void robotArmsAnimation() {
	//////////////////////////////////////////////////////////////////////////////////////////////
	int bigleg_speed = 1;
	int smallleg_speed = 2;
	//leg movement
		if (rightLegForward) {
			bigleg_r_right += 1;
			if (smallleg_r_right > -50)
				smallleg_r_right -= 2;
		}
		else {
			bigleg_r_right -= 1;
			if (smallleg_r_right < 0)
				smallleg_r_right += 2;


		}
		if (bigleg_r_right > 30 || bigleg_r_right <= -30) {
			rightLegForward = !rightLegForward;
		}

		if (leftLegForward) {
			bigleg_r_left += 1;
			if (smallleg_r_left > -50)
				smallleg_r_left -= 2;
		}
		else {
			bigleg_r_left -= 1;
			if (smallleg_r_left < 0)
				smallleg_r_left += 2;


		}
		if (bigleg_r_left > 30 || bigleg_r_left <= -30) {
			leftLegForward = !leftLegForward;
		}
	//arm movement
	if (rightArmForward) {
		shoulder_r_right += 1;
		if (elbow_r_right < 50)
			elbow_r_right += 2;
	}
	else {
		shoulder_r_right -= 1;
		if (elbow_r_right > 0)
			elbow_r_right -= 2;
	}
	if (shoulder_r_right > 30 || shoulder_r_right <= -30) {
		rightArmForward = !rightArmForward;
	}
	if (leftArmForward) {
		shoulder_r_left += 1;
		if (elbow_r_left < 50)
			elbow_r_left += 2;
	}
	else {
		shoulder_r_left -= 1;
		if (elbow_r_left > 0)
			elbow_r_left -= 2;
	}
	if (shoulder_r_left > 30 || shoulder_r_left <= -30) {
		leftArmForward = !leftArmForward;
	}
	//movement
	robotloc += 0.005;
	if (robotloc > 0.5) {
		robotloc = -0.5;
	}
	glutPostRedisplay();
	////////////////////////////////////////////////////////////////////////////////////////////////////

 

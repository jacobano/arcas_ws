# It contains the state estimation of an object like a bar, landing and takeoff marks, basis of a bar, etc. The object state is formed by its position, its orientation,
# an identifier and the object type.

# The object position measured in meters [m] with respect to the testbed frame (also known as map frame or global frame).
Position position

# The object orientation measured in radians [rad] with respect to the testbed frame (also known as map frame or global frame).
Attitude attitude

# The object identifier.
int32 identifier

# To be defined in an enumerated.
int32 object_type
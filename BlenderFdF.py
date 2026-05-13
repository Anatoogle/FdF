import bpy

obj = bpy.context.active_object
mesh = obj.data

filepath = "home/vertex.plus"

with open(filepath, "w") as f:

    # vertices
    for v in mesh.vertices:
        co = v.co
        f.write(f"{v.index},{co.x},{co.y},{co.z}\n")

    f.write("\n")

    # edges
    for e in mesh.edges:
        f.write(f"{e.vertices[0]},{e.vertices[1]}\n")

print(f"Exported to {filepath}")
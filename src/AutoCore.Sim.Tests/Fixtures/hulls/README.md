Real convex-hull entries extracted from the client's physics.glm (see
docs/reconstruction/physics/hull-format-findings.md for the byte layout):

- box.{cache,tk} — editor unit cube; canonical constants (6 planes, 8 verts,
  COM (0,0.5,0), unit-mass inertia diag 1/6).
- obj_gen_bj_mov_01_husk_sportscar-p2.{cache,tk} — off-origin decomposition
  piece with a non-diagonal inertia tail.
- obj_f_m_static_str_02_windmill.{cache,tk} — mid-size static prop hull.

.tk is the ASCII source (vert count, verts, tri count, tris); .cache is the
compiled binary the parser targets. Extract more with
scripts/list_glm_contents.py physics.glm -f <name> -e <out>.

# Annotated low-level: ParticleFluidPhase_CreateFluidParticles_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004c1cb0` |
| VA | `0x004c1cb0`–`0x004c207c` exclusive (**972 B** / `0x3CC`) |
| Ghidra | `FUN_004c1cb0` |
| Named | `ParticleFluidPhase_CreateFluidParticles_Inferred` |
| System | client / particle fluid phase |
| Date | 2026-07-29 (W34-N dual seal; scaffold 2026-07-23) |

## Machine-level notes

- **ABI:** `__thiscall`; ECX = `phase*`; stack `int capacity`; void; `RET 4`.
- **Sole caller:** `ParticleFluidPhase_Init_Inferred` @ `0x004c209b` with hard `push 0x7fff` (32767).
- **Product name:** error format `Invalid arg to CreateFluidParticles %u` (and vert/index/lock variants) — **Confirmed** stem.
- **Depends on prior fluid-bump child:** optional `NormalMapTexture` uses `phase+0x94` (written by `004c0a90`).
- **Capacity layout:** `+0xbc = capacity`, `+0xb8 = capacity * 4` (vertex count), particle stride path uses `capacity * 0x70` array + `FUN_00404d80` element size `0x1c` over `capacity*4` slots.
- Prefer bytes when decompiler conflicts.

## Control flow (annotated)

```c
// __thiscall; ECX=phase*; stack capacity; RET 4; void
void ParticleFluidPhase_CreateFluidParticles_Inferred(void *phase, int capacity)
{
  // SEH LAB_009a1b4a
  int verts = capacity * 4;
  *(int *)((char *)phase + 0xbc) = capacity;
  *(int *)((char *)phase + 0xb8) = verts;

  if (verts == 0) {
    FUN_007a4480(1, "Invalid arg to CreateFluidParticles %u", 0);
    return; // RET 4
  }
  // bytes also have redundant cmp verts,0xffff / jae continue; only zero rejects

  // particle storage: capacity * 0x70 bytes, construct 0x1c-stride × verts
  void *particles = operator_new__(capacity * 0x70);
  if (particles)
    FUN_00404d80(particles, 0x1c, verts, FUN_005edf20);
  *(void **)((char *)phase + 0xb4) = particles;

  // view-ish 0x14c @ +0xac
  void *v = operator_new(0x14c);
  void *view = v ? FUN_00764030(/*this=v*/) : 0;
  *(void **)((char *)phase + 0xac) = view;
  FUN_007638d0(view, 1);
  // pack two float3 colors from DAT_00a1401c / DAT_00aaab38
  // view->vtbl[+0x4c](colorA, colorB); FUN_0074b8f0(...)

  // mesh/draw 0xc4 @ +0xb0
  void *m = operator_new(0xc4);
  void *mesh = m ? FUN_00748960(/*this=m*/) : 0;
  *(void **)((char *)phase + 0xb0) = mesh;

  // FX + textures
  // NDParticleFluid.fx → FUN_009701d0
  // Particles.dds → FUN_0096f3e0(..., 0)
  FUN_00970140("ParticleTexture", capacity);
  if (*(int *)((char *)phase + 0x94) != 0)
    FUN_00970140("NormalMapTexture", *(int *)((char *)phase + 0x94));
  // optional ReflectionSurface via phase+0xa8 child + FUN_005b3400

  FUN_004148e0((char *)phase + 0x8c);
  *(uint32_t *)((char *)mesh + 0xbc) |= 1;       // busy / building

  // allocate VB for verts (phase+0xb8), FVF/path 0x1c2 via FUN_007478c0
  // allocate IB for capacity*6 indices
  // lock → FUN_004c05d0 fill → unlock
  // mesh+0xa8 = 0; mesh+0xac = 5; clear busy bit; FUN_007647c0(mesh)

  // error logs (non-fatal branches):
  //   "Unable to allocated %u verts for fluid particles"
  //   "Unable to allocated %u indices for fluid particles"
  //   "Unable to lock %u indices for fluid particles"
}
```

## Phase field map (this unit + peer)

| Offset | Written by | Role |
|---|---|---|
| `+0x94` | `004c0a90` | Normal-map texture handle cache |
| `+0x9c` | `004c0a90` | Fluid-bump render child (0x198) |
| `+0xac` | `004c1cb0` | 0x14c view-ish object |
| `+0xb0` | `004c1cb0` | 0xc4 mesh/draw object |
| `+0xb4` | `004c1cb0` | particle array (`capacity*0x70`) |
| `+0xb8` | `004c1cb0` | vertex count (`capacity*4`) |
| `+0xbc` | `004c1cb0` | particle capacity |

## Open questions

- Product demangle for `FUN_00764030` / `FUN_00748960` / `FUN_00404d80` element type.
- Whether capacity is data-driven anywhere beyond Init hardcode `0x7FFF`.
- Full mesh flag enum for `+0xac = 5` / busy bit at `+0xbc`.
- Runtime / bit-exact / differential / OOM partial-init.

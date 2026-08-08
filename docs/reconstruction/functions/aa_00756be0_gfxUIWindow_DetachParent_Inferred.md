# Function record: gfxUIWindow_DetachParent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756be0` |
| **Canonical name** | `gfxUIWindow_DetachParent_Inferred` |
| **Prior scaffold** | `FUN_00756be0` |
| **Rejected misname** | `Named_CalleeOf_Named_gfxUIWindow_00756be0` (xref-seed) |
| **Address** | `0x00756be0`–`0x00756c44` inclusive (**101 B** / `0x65`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / gfxUIWindow child-list unlink |
| **Agent** | MEGA-121 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps** — CF/ABI/offsets sealed; product demangle open) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC client **gfxUIWindow** family helper: remove a child window pointer from the parent's dense child list and clear the child's parent back-pointer.

```text
gfxUIWindow_DetachParent_Inferred(parent, child) -> status
  begin = parent.children_begin (+0x94)
  end   = parent.children_end   (+0x98)
  find child* in [begin, end)
  if miss: return 0xffffffff
  memmove compact slot; end -= 4
  child.parent_link (+0x88) = 0
  return 0
```

Used when:

1. A child is destroyed and must leave its parent (`gfxUIWindow_CompleteDtor` if `+0x88`).
2. A dialog tears down hash-owned children (`CNDUIDialog_TeardownChildHash_Inferred`).
3. Reparent paths detach from the old parent first (`FUN_00756c50` residual).

## Signature (decompiler + bytes + dualed call sites)

```c
// __thiscall; RET 4
// ECX = parent window/dialog; stack = child window*
// EAX = 0 success / 0xffffffff not found
std::uint32_t __thiscall gfxUIWindow_DetachParent_Inferred(
    void *parent,
    void *child);
```

| Item | Value |
|---|---|
| Parent vector begin | `+0x94` |
| Parent vector end | `+0x98` |
| Child parent link | `+0x88` |
| Sole callee | `memmove` @ IAT `0x009c652c` |
| Element size | 4 (pointer) |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_00756be0_FUN_00756be0.md`
- Annotated: `docs/reconstruction/raw/aa_00756be0_FUN_00756be0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/gfxUIWindow_DetachParent_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00756be0.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00756be0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00756be0_gfxUIWindow_DetachParent_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00756be0_gfxUIWindow_DetachParent_Inferred.md`
- Report: `docs/agents/task-dual-ab-00756be0-mega-121-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `memmove` | IAT `0x009c652c` |
| Callers | **24** UNCONDITIONAL_CALL | UI detach / reparent / teardown |
| Sample dualed | `gfxUIWindow_CompleteDtor` `0x00759de0` @ `0x00759f3a` | `ECX=[self+0x88]`; `PUSH self` |
| Sample dualed | `CNDUIDialog_TeardownChildHash_Inferred` `0x007917c0` @ `0x007918a5` | `ECX=dialog`; `PUSH child` |
| Peer residual | `FUN_00756c50` | attach / reparent |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| `__thiscall` + `RET 4` + EAX status | **Confirmed** |
| Offsets `+0x94`/`+0x98`/`child+0x88` | **Confirmed** |
| Role vs free/dtor/walk-all | **Confirmed reject misclaims** |
| Product method demangle | **Tentative** (`_Inferred`) |
| Runtime | **Open** |

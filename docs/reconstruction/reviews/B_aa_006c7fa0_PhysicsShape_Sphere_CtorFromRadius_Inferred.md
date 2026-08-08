# Review B (skeptical / adversarial): `aa_006c7fa0` PhysicsShape_Sphere_CtorFromRadius_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7fa0` |
| **VA** | `0x006c7fa0` |
| **Canonical name** | `PhysicsShape_Sphere_CtorFromRadius_Inferred` |
| **Review date** | `2026-08-05` (MEGA-071 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is a **VOG_DEBUG_STOP** helper / callee of debug-stop | **Falsified** — 0 of 18 xrefs from debug-stop; VOG_DEBUG_STOP is AABB-fail branch of GetObjectsInArea (sibling of mode-2, not parent of this VA) |
| 2 | **Box / AABB / capsule** shape ctor | **Falsified** — vtbl methods use single radius@+0xc: AABB inflate by r, support+r, ray-sphere quadratic (`radius*radius`) |
| 3 | **stdcall / fastcall / no cleanup** | **Falsified** — `MOV EAX,ECX` + stack arg + terminal **`RET 4`** |
| 4 | Stack arg is **int flags / mode**, not radius | **Falsified** — mode-2 parent decompile `FUN_006c7fa0(param_3)` where `param_3` is float radius/extent; call sites `PUSH` float from parent radius slot |
| 5 | Object size **>0x10** or embeds center | **Falsified** — alloc sites request **0x10**; center is separate stack copy after CALL in mode-2 |
| 6 | Non-leaf / has callees | **Falsified** — analyze `callees:[]`; no CALL in body hex |
| 7 | Writes size tag @+0x04 | **Falsified** — body writes +6/+8/+0xc/+0 only; parent writes `word[+4]=0x10` |
| 8 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 9 | Product demangle sealed | **Fails** — no RTTI/string on body → `_Inferred` required |

---

## 2. Decisive machine dataflow

```text
MOV EAX, ECX                 // this
MOV ECX, [ESP+4]             // stack float radius
MOV word ptr [EAX+6], 1      // refcount
MOV dword ptr [EAX+8], 0
MOV [EAX+0xc], ECX           // radius
MOV dword ptr [EAX], 0xa0d610
RET 4
```

Mode-2 call-site (`0x004ea6ce` in `FUN_004ea350`):

```text
// (*DAT_00b05060+0x10)(0x10, 0x22)
MOV word ptr [EAX+4], 0x10
PUSH radius                  // parent param_3
MOV ECX, EAX
CALL 0x006c7fa0
// center from param_2 copied after; collector FUN_005ebec0
```

Vtbl proof (`00a0d610[+6]=006c7f20`):

```text
// expands AABB by *(float*)(shape+0xc) — pure sphere inflate
param_3 = param_3 + *(float *)(param_1 + 0xc);
// min = object_min - r; max = object_max + r
```

Vtbl proof (`00a0d610[+8]=006c7fc0`): ray vs sphere uses `r*r` at +0xc — not box/capsule.

A ≡ B on live decompile + body hex + xrefs + call-site context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf ctor CF / stores | **High** | wrong port |
| thiscall + RET 4; EAX=this | **High** | stack smash |
| radius@+0x0c float | **High** | wrong query radius |
| Sphere vtbl family | **High** | wrong shape math |
| Caller set (18) | **High** | missing sites |
| Product English | Medium | naming only |
| field@+0x08 English | Low | cosmetic |

---

## 4. Surviving contract for AutoCore

```csharp
// 0x10-byte sphere shape setup (post-alloc)
// thiscall RET 4; ECX=shape; stack float radius; EAX=shape
SphereShape CtorFromRadius(SphereShape self, float radius)
{
    self.RefCount = 1;          // +0x06
    self.Field08 = 0;           // +0x08
    self.Radius = radius;       // +0x0c
    self.Vtbl = SphereVtbl_00a0d610;
    return self;
}
// Caller pre-tags size@+0x04 = 0x10 after heap(0x10, 0x22).
// Keep distinct from AABB default GetObjectsInArea path and box mode-1.
// Do not bind to VOG_DEBUG_STOP plate.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/sphere role/callers. Residual product demangle + field@+0x08 English → **accept-with-gaps**.

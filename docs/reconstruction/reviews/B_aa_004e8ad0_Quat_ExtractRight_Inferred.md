# Review B (skeptical / adversarial): `aa_004e8ad0` Quat_ExtractRight_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8ad0` |
| **VA** | `0x004e8ad0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e8ad0_Quat_ExtractRight_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is **forward (+Z)** basis | Confuse with `0x004e8a40` | **Falsified** — formula is matrix **column 0** (right): `1−2(y²+z²)`, not `1−2(x²+y²)` on Z |
| 2 | This is **up (+Y)** basis | Confuse with `0x004e8b60` | **Falsified** — up has `out.y = 1−2(x²+z²)`; this writes that pattern on **out.x** |
| 3 | Quaternion layout is **WXYZ** | Havok-style pack swap | **Falsified** — loads `*p,p[1],p[2],p[3]` as x,y,z,w; identity `(0,0,0,1)` → right `(1,0,0,0)` only for XYZW |
| 4 | Output is a full **row** of R (not column) | Row-major confusion | **Falsified** — matches standard column-0 (local +X in world); MoveToTarget dots as lateral axis |
| 5 | Function **normalizes** quat or result | Defensive port assumption | **Falsified** — leaf; no sqrt/rsqrt; non-unit in → non-unit out |
| 6 | `g_flLevelUpUiBase_Inferred` is a UI level constant *in this body* | Plate name | **Falsified as role** — value is **2.0f** scale only (`00 00 00 40`); UI plate is cross-use misnomer |
| 7 | `__thiscall` / ECX object | Vehicle entity habit | **Falsified** — stack `[ebp+8]`/`[ebp+0xc]`; no ECX this |
| 8 | Named alias *only* means “AI DecideHeading helper” | Parent-seed rename | **Falsified as exclusive role** — **22** xrefs: drive, camera, turret, net, AI, UI |
| 9 | Writes only float3 (no W) | Stack size | **Falsified** — explicit `out[3]=0` 16-byte write |
| 10 | Name `Quat_ExtractRight` is string-proven | Symbol inflation | **Not sealed** — **Probable / `_Inferred`** from math + consumers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Right (+X) formula / column 0 | **High** | Steer lateral inverted / wrong axis |
| XYZW component order | **High** | Silent 90° frame errors |
| Constants 1.0 / 2.0 addresses | **High** | Wrong scale if relocated blindly |
| Sibling F/U separation | **High** | Swap R/F in ports |
| Leaf purity (no side effects) | **High** | Over-port normalize breaks parity |
| Product English name | **Medium** | Doc only |
| Complete caller English roles | **Low–Med** | Miss non-drive consumers |
| Behavior under non-unit quat | **High CF / open product intent** | Length drift if callers dirty |

---

## 3. Cross-check against raw

```text
// raw aa_004e8ad0 ≡ live decompile 2026-07-29
// q = (x,y,z,w) = (*p, p[1], p[2], p[3])
// TWO @ 0xa10e74 = 2.0; ONE @ 0xa0f2a0 = 1.0

out[0] = ONE - (z*z + y*y) * TWO;   // 1 - 2(y²+z²)
out[2] = (z*x - y*w) * TWO;         // 2(xz - yw)
out[1] = (x*y + z*w) * TWO;         // 2(xy + zw)
out[3] = 0;

// Sibling NOT this VA:
//   0x004e8a40 → forward column 2
//   0x004e8b60 → up     column 1
```

Clean scaffold `FUN_004e8ad0.cpp` ≡ raw outline (no invent branches).

---

## 4. Surviving contract for AutoCore

```
Quat_ExtractRight_Inferred(quat_xyzw[4], out[4]):
  // pure leaf; stack args; no normalize
  x,y,z,w = quat[0..3]
  out[0] = 1.0 - 2.0 * (y*y + z*z)
  out[1] = 2.0 * (x*y + z*w)
  out[2] = 2.0 * (x*z - y*w)
  out[3] = 0.0

// Shared pool constants (image):
//   DAT_00a0f2a0 = 1.0f
//   DAT_00a10e74 = 2.0f   // NOT "level-up UI" here

// Pair with:
//   Quat_ExtractForward @ 0x004e8a40
//   Quat_ExtractUp      @ 0x004e8b60  (sibling; not this dual)

// Known consumers of RIGHT:
//   MoveToTarget3DPoint lateral = dot(R, aimDir)
//   Camera ApplyLookOffset right basis
//   AI DecideHeading, turret aim, many others
```

**Port tests that matter:**

* Identity quat → `(1,0,0,0)`.
* Must **not** implement forward formula at this VA.
* Must use **XYZW**, not WXYZ.
* Must write **W=0** if matching 16-byte packs.
* Must **not** re-normalize unless source quat is known dirty and product intent changes (retail does not).
* Do not treat `g_flLevelUpUiBase_Inferred` name as domain meaning — value is **2.0**.

---

## 5. Open questions

1. Official product / Havok helper name (none in image strings).
2. English roles for remaining `FUN_*` callers beyond drive/camera/AI/turret.
3. Runtime CE samples: identity + 90° yaw right/forward pair.
4. Whether any producer writes non-unit quat into `rb+0x30` before this leaf.

**Verdict:** **accept-with-gaps** — adversarial attacks on axis identity, WXYZ, thiscall, exclusive-AI naming, and UI-constant role **fail**; remaining gaps are product naming / runtime / full caller English only.

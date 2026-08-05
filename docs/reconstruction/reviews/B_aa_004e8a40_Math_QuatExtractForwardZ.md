# Review B (skeptical / adversarial): `aa_004e8a40` Math_QuatExtractForwardZ

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8a40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004e8a40_Math_QuatExtractForwardZ.md` |
| **System** | `input-drive-control` (pure math leaf) |
| **Dual status** | **Present** |
| **Verdict** | **accept** on forward (+Z) extract formula + constants + leaf CF; **reject** overclaims that this unit writes drive axes, is right/up extract, normalizes, or uses WXYZ |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is PushDriveAxes thr/HB bridge | **Falsified** — body is pure quat→vec; no entity/controller offsets |
| 2 | Output is right (+X) axis | **Falsified** — formula is matrix **column 2** (forward +Z); right is sibling `0x004e8ad0` |
| 3 | Output is up (+Y) axis | **Falsified** — up is sibling `0x004e8b60` |
| 4 | Quaternion layout is WXYZ | **Falsified** — `*param_1`=x, `[1]`=y, `[2]`=z, `[3]`=w (XYZW) |
| 5 | Function re-normalizes quat or output | **Falsified** — no sqrt/div; non-unit in → non-unit out |
| 6 | `g_flLevelUpUiBase_Inferred` is a UI scale here | **Falsified role** — `read_memory` = **2.0f**; shared pool misnomer |
| 7 | `g_flOne` is not 1.0 | **Falsified** — LE `00 00 80 3f` |
| 8 | W of output is left undefined | **Falsified** — explicit store `param_2[3] = 0.0` |
| 9 | `__thiscall` with entity in ECX | **Falsified** — two stack float* args; no `this` |
| 10 | Scaffold alias `Named_CalleeOf_Client_DebugDumpEntityCombatStats_*` is the product identity | **Rejected as name** — debug is one of many callers; identity is forward extract |
| 11 | Ready only as “unknown” system forever | **Rejected** — drive consumers establish role; system tag `input-drive-control` + pure math leaf |
| 12 | Dual requires re-owning PushDriveAxes body | **Rejected** — OWN-ONLY this VA; consumer dual already seals call site |

---

## 2. Decisive dataflow (raw ≡ live)

```
// param_1 = const float q[4]  // XYZW
// param_2 = float out[4]

TWO = *(float*)0x00a10e74        // 2.0
x = q[0]; y = q[1]; z = q[2]; w = q[3]

out[0] = (z*x + y*w) * TWO       // 2(xz + yw)
out[1] = (z*y - x*w) * TWO       // 2(yz - xw)
out[2] = 1.0 - (x*x + y*y) * TWO // 1 - 2(x²+y²)   // ONE @ 0x00a0f2a0
out[3] = 0.0
return
```

Live re-decompile (2026-07-29) matches 2026-07-23 raw. Constants re-verified via `read_memory`.

### Hand checks (adversarial algebra)

| Input quat `(x,y,z,w)` | Expected forward | Body produces? |
|------------------------|------------------|----------------|
| Identity `(0,0,0,1)` | `(0,0,1,0)` | **Yes** — all off-diag 0; z-term = 1 |
| 90° about +Y: `(0, √½, 0, √½)` | `(1,0,0,0)` | **Yes** — `out.x = 2*(0 + √½·√½)=1`; `out.z = 1-2*(0+½)=0` |

Matches local **+Z forward** (with siblings +X right / +Y up).

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Formula terms / sign of each product | **High** | Wrong heading / reverse polarity in all consumers |
| XYZW component order | **High** | Silent 90° errors if WXYZ ported |
| TWO=2.0 / ONE=1.0 addresses | **High** | Wrong scale if swapped with other DAT pools |
| W output forced 0 | **High** | Dirty stack if port skips W write into 16-byte packs |
| Not thr/HB/steer writer | **High** | Mis-attribution of drive bridge |
| Sibling right/up not this VA | **High** | Swapped axes in port |
| Runtime golden | **Open** | Residual parity only |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `out.x = 2(zx + yw)` | Sign invent? | **No** — live `(fVar3*fVar1 + fVar2*fVar4)*TWO` |
| `out.y = 2(zy − xw)` | Sign invent? | **No** — live `(fVar3*fVar2 - fVar1*fVar4)*fVar5` |
| `out.z = 1 − 2(x²+y²)` | Wrong diagonal? | **No** — live `g_flOne - (fVar1*fVar1 + fVar2*fVar2)*fVar5` |
| `out.w = 0` | Optional? | **No** — always written |
| Constant 2.0 at `0xa10e74` | Guess? | **No** — `00 00 00 40` this pass |
| Constant 1.0 at `0xa0f2a0` | Guess? | **No** — `00 00 80 3f` this pass |
| Body has entity `+0x614` thr | Hidden? | **None** |
| Normalize step | Hidden? | **None** |

---

## 5. Surviving contract for AutoCore

```
Math_QuatExtractForwardZ(const float q[4] /* XYZW */, float out[4]):
  // unit quat preferred; retail does not normalize
  out[0] = 2.0f * (q[2]*q[0] + q[1]*q[3])
  out[1] = 2.0f * (q[2]*q[1] - q[0]*q[3])
  out[2] = 1.0f - 2.0f * (q[0]*q[0] + q[1]*q[1])
  out[3] = 0.0f
```

**Consumers (not owned here):** PushDriveAxes overspeed polarity, MoveToTarget3DPoint align/speed dots, applyAction, AI heading — all treat XYZ as chassis **+Z forward**.

**Port cautions:**

- Input **must** be XYZW (Havok/client chassis layout).
- Do **not** re-normalize unless source quat is known non-unit and product requires unit direction.
- Keep 16-byte write including W=0 when matching retail stack packs.
- Sample quat once if extracting right+forward under concurrent physics (MoveToTarget re-reads pointer twice — consumer issue).

---

## 6. Open questions

1. Optional runtime golden table (identity / 90° yaw / 180° yaw) vs live client.
2. Whether any non-unit quat producer relies on scaled (non-unit) forward — body allows it.
3. Sibling right/up duals if not already sealed on their own VAs (out of OWN-ONLY scope).

**Verdict:** **accept** — adversarial pass cannot break formula, constants, leaf CF, or forward-axis identity. Reject only naming/system scaffold leftovers and drive-bridge confusions.

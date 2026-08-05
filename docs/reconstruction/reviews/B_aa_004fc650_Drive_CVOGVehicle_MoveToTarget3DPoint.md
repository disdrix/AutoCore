# Review B (skeptical / adversarial): `aa_004fc650` Drive_CVOGVehicle_MoveToTarget3DPoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fc650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fc650_Drive_CVOGVehicle_MoveToTarget3DPoint.md` |
| **Verdict** | **accept-with-gaps** on CF; **UF-007 sealed High (static)** |
| **Evidence** | Ghidra MCP `batch_decompile` `0x004fc650` + `0x004f5620` (2026-07-29) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Player keyboard drive tick | Body is AI MoveToTarget writer (string + thr/steer path) | **Falsified** |
| 2 | Never uses SetSteerInput | Deadband hard-spin path calls it | **Falsified** |
| 3 | UF-007: inline gate **parenthesization differs** from SetSteerInput three-load | Live decompile: identical `*(*(*(this+4)+4)+0xb0+this)` | **Falsified** |
| 4 | UF-007: expanded bits **not** equal to `0xC7` | Bits 1\|2\|4\|0x40\|0x80 = 0xC7; AND-of-clears ≡ mask==0 | **Falsified** |
| 5 | Deadband bypasses steer lock | Calls SetSteerInput which re-applies gate | **Falsified** (end-effect) |
| 6 | Finished bit-exact gains / runtime goldens | No emulate/diff this pass; prior constants only | **Still overstated if claimed complete** |
| 7 | Thr always gated like steer | Drive path stores `+0x614` direct | **Survives** (real residual) |

---

## 2. Adversarial re-read of parenthesization

Loose historical forms:

```text
// Ambiguous / easy-to-misread (drive-controller-spec §4 style):
wobj = *( *(this+4)+4 + this + 0xb0 )     // looks like p0+offset single load

// SetSteerInput sealed form:
wobj = *( *(*(this+4)+4) + this + 0xb0 )  // three loads
```

**Attack:** maybe MoveToTarget really used the 2-load form and UF-007 was a real CF fork.

**Counter-evidence (live decompile both):**

```c
// 0x004f5620
*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1)

// 0x004fc650 proportional gate
*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1)
```

Same AST. **No fork.** Residual was documentation ambiguity, not binary divergence.

**Attack on bit expansion:** compiler could have dropped a bit or ORed extra.

**Counter-evidence:** decompile tests exactly `2, 4, 1, 0x80, 0x40` — no `0x08/0x10/0x20`. Union is `0xC7` only. Nested `&&` of “bit clear” is De Morgan dual of “any bit set” used to **skip** the store when mask non-zero.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Axis offsets `+0x614/+0x618/+0x61c` | High | Wrong NPC drive pack |
| Body gate `+0x101` | High | Drive while frozen |
| Three-load ≡ SetSteerInput | **High** | False port gate / wrong object |
| Expanded bits ≡ `0xC7` | **High** | Lock mismatch |
| Proportional vs hard steer split | High | Oscillate / spin |
| Deadband end-effect gated | High | Invented unlock |
| param_2 radius / param_3 cruise names | Tentative | Stop distance wrong |
| Float gain bit-exact without re-read constants | Medium | Soft path drift |
| Direct thr ungated on drive path | High (as binary fact) | Over-gating thr in port |

---

## 4. Cross-check against raw / live

```
if body && !frozen:
  delta pos; if far/heading:
    proportional: three-load wobj; expanded 0xC7 allow → +0x618
    deadband: SetSteerInput(0 or ±1)  // callee gates
    thr bulk +0x614; sharp +0x61c; push
  arrival: thr0 + push
Clean ≡ raw outline; UF-007 parenthesization residual closed.
```

---

## 5. Surviving contract for AutoCore

```
MoveToTarget3DPoint(vehicle, acceptDist, cruiseScale, aim_UNUSED, allowReverse):
  AI path write thr/steer/HB then PushDriveAxes
  proportional +0x618 uses SAME three-load + 0xC7 allow as SetSteerInput
  deadband steer goes through SetSteerInput (gated)
  thr +0x614 on drive path is direct (not via SetLongitudinal)
  pair MapPath_AdvanceAndSteer + HBAIDriver
  AutoCore NpcVehiclePathFollower axis ownership critical
```

---

## 6. Open questions (after UF-007 close)

1. Seal param_2/3 role names at High if still only Medium from prior plate.
2. UF-001 / UF-002 — `wobj` type and per-bit semantics (shared with SetSteerInput).
3. Live AI drive capture vs controller (runtime).
4. Whether port should gate thr the same as steer for safety (binary does not on main path).

**Verdict:** **accept-with-gaps** on CF; **UF-007 sealed High (static)**; do not claim unit complete.

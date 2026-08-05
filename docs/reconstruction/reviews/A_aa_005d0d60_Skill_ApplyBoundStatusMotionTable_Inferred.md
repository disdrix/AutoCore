# Review A (reconstruction fidelity): `aa_005d0d60` Skill_ApplyBoundStatusMotionTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d0d60` |
| **VA** | `0x005d0d60`–`0x005d126d` |
| **Canonical name** | `Skill_ApplyBoundStatusMotionTable_Inferred` |
| **Ghidra name** | `FUN_005d0d60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-A) |
| **Counterpart** | `reviews/B_aa_005d0d60_Skill_ApplyBoundStatusMotionTable_Inferred.md` |
| **System** | skills / status-motion |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry, mid, epilogue, constants) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply a **skill-id keyed status/motion table entry** on a bound controller:

1. Require `ctl+0x18` (spawn) non-null; optional spawn activate.
2. Walk tree rooted at entity chain `…+0x520`; scan `0x18`-byte rows for `skillId`.
3. On hit: `ctl+0x30 = (tickMs + durationMs) * 0.001`.
4. If duration ≠ 0 and entry+0x0a: set entity status flags, optional Y-impulse, handbrake, heading/rotation.
5. Always when duration ≠ 0: `entity+0x306 = 1`.
6. Switch entry+0x0b → `entity.vtbl[+0x64](code, 0.1f, 1, -1.0f)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d0d60_FUN_005d0d60.md` (+ W22-A append) |
| Annotated | `docs/reconstruction/raw/aa_005d0d60_FUN_005d0d60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ApplyBoundStatusMotionTable_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d0d60.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d0d60_FUN_005d0d60.md` |
| Caller dual | `aa_004c2f20` Skill_ApplyBoundStatusMotionIfPresent (tail JMP) |
| Live | decompile ≡ raw; RET 4 sealed; constants sealed |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 4
void Skill_ApplyBoundStatusMotionTable_Inferred(void *ctl, int skillId);
```

| Formal | Source | Conf |
|---|---|---|
| ctl | ECX (`8b f9`) | **High** |
| skillId | `[EBP+8]` (`8b 4d 08` at compare) | **High** |
| ABI | `c2 04 00` @ `0x005d126b` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if *(ctl+0x18)==0: return
// optional spawn active
// tree walk; scan entries stride 0x18 for skillId
if !found: return
ctl+0x30 = (tick + durMs) * 0.001
if durMs != 0:
  if entry+0x0a: flags/impulse/handbrake/heading
  entity+0x306 = 1
switch entry+0x0b:
  1→vtbl+0x64(3,0.1,1,-1); 2→(4,…); 3→(0x10,…); 4→(0x11,…)
```

| Stage | Match | Conf |
|---|---|---|
| thiscall RET 4 | **Yes** | **High** |
| Stride 0x18 skill match | **Yes** | **High** |
| End-time formula | **Yes** | **High** |
| Mode map 1..4 | **Yes** | **High** |
| Y-impulse (0, y, 0, 0) | **Yes** (bytes zero X after load) | **High** |
| Tree successor structure | **Yes** (decomp) | **Medium** (complex) |

---

## 5. Machine bytes (`read_memory`)

Entry:
```
558bec83e4f083ec345356578bf9...
```

Epilogue:
```
...8be55dc20400
```

| Constant | VA / imm | Value |
|---|---|---|
| ms→s | `0x00a0f72c` | 0.001 |
| tick bias | `0x00aaa5dc` | 4294967296.0 |
| dist ε | `0x009da864` | ~1.192e-7 |
| mode scale | `0x3dcccccd` | 0.1f |
| mode floor | `0xbf800000` | −1.0f |

---

## 6. Confidence / gaps

| Claim | Conf |
|---|---|
| ABI + table apply CF | **High** |
| Sole caller tail from 004c2f20 | **High** |
| Mode code English | **Open** |
| Status flag English (+0x304..306) | **Open** |
| Full tree type recovery | **Open** |

**Verdict: accept-with-gaps** — apply kernel sealed for ports; product mode names residual.

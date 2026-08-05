# Review A (reconstruction fidelity): `aa_004c4dd0` Combat_ComputeBaseCritChance_FromHost

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4dd0` |
| **VA** | `0x004c4dd0`–`0x004c4e1d` |
| **Canonical name** | `Combat_ComputeBaseCritChance_FromHost` |
| **Ghidra name** | `FUN_004c4dd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-K) |
| **Counterpart** | `reviews/B_aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md` |
| **System** | combat-crit |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; UI/callee context |
| **Verdict** | **accept** |

---

## 1. Purpose

Base **critical-hit chance** fraction for skill-host path:

`chance = (score + level) * 0.001 * 0.125 + 0.02`

where `level = vcall(+0x27c)`, `score = FUN_004c41c0(host)`. UI labels **"Base Critical Hit Chance"**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c4dd0_FUN_004c4dd0.md` (+ W23-K append) |
| Annotated | `docs/reconstruction/raw/aa_004c4dd0_FUN_004c4dd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Combat_ComputeBaseCritChance_FromHost.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4dd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md` |
| Parent | `Combat_ComputeCritChance_Inferred` `0x004cef70` |
| Live | decompile ≡ raw; 77 B body; constants `read_memory` |

---

## 3. Signature (sealed)

```c
// __fastcall; ECX=host; ST0 return
float Combat_ComputeBaseCritChance_FromHost(void* host);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX → ESI | **High** |
| return | ST0 | **High** |
| stack formals | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
level = vcall(mi(+0x27c))
ST0 = level * 0.001
score = FUN_004c41c0(host)
ST0 = score * 0.001 + ST0
ST0 = ST0 * 0.125 + 0.02
return ST0
```

| Stage | Match | Conf |
|---|---|---|
| vcall +0x27c | **Yes** | **High** |
| *0.001 both terms | **Yes** | **High** |
| FUN_004c41c0 | **Yes** | **High** |
| *0.125 + 0.02 | **Yes** | **High** |
| UI "Base Critical Hit Chance" | **Yes** | **High** |
| Parent bind path only | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
51568bf1...d805b8a7aa0059   (77 B full hex in raw)
```

| Constant | VA | Value |
|---|---|---|
| g | `0x00a0f72c` | 0.001f |
| scale | `0x00a110c0` | 0.125f |
| base | `0x00aaa7b8` | 0.02f |

Callee: `FUN_004c41c0` @ `0x004c41c0`.

---

## 6. Gaps

- Host product type from `vtbl+0x214` (bind vs self).
- Full `FUN_004c41c0` / `+0x27c` English (callee residual).
- Runtime / bit-exact.

**Residual gaps non-blocking for formula/ABI.** Verdict **accept**.

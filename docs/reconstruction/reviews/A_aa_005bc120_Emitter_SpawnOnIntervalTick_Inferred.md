# Review A (reconstruction fidelity): `aa_005bc120` Emitter_SpawnOnIntervalTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc120` |
| **VA** | `0x005bc120`–`0x005bc3bc` |
| **Body** | **669** bytes / `0x29D` |
| **Canonical name** | `Emitter_SpawnOnIntervalTick_Inferred` |
| **Ghidra name** | `FUN_005bc120` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-I) |
| **Counterpart** | `reviews/B_aa_005bc120_Emitter_SpawnOnIntervalTick_Inferred.md` |
| **System** | client::fx / emitter |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; caller site |
| **Verdict** | **accept** |

---

## 1. Purpose

Emitter host **interval spawn tick**:

1. Accumulate rate `+0x928 += +0x930 * *dt`.
2. Subtract `*dt` from countdown `+0x804`; if still `> 0` → return.
3. Compute group count (1, or vector `(end-begin)/0xC` when flag `+0x98C & 0x80`).
4. Clear per-node flag `+0x2ee` on circular ring; skip spawn if empty name.
5. For each group: spawn up to `short(+0x8E4)` entities while under active cap; create/list/motion/optional pair.
6. Reschedule: `+0x804 = base(+0x8DC) + range(+0x8E0) * (u16_rng * DAT_00aaa638)` with `DAT_00aaa638 ≈ 1/65535`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005bc120_FUN_005bc120.md` (+ W26-I append) |
| Annotated | `docs/reconstruction/raw/aa_005bc120_FUN_005bc120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Emitter_SpawnOnIntervalTick_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005bc120.cpp` |
| Function record | `docs/reconstruction/functions/aa_005bc120_FUN_005bc120.md` |
| Named record | `docs/reconstruction/functions/aa_005bc120_Emitter_SpawnOnIntervalTick_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` body+epilogue; call site @ `0x005bdcc1` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = emitter; stack float* dt, uint32_t motionCtx; RET 8; void
void Emitter_SpawnOnIntervalTick_Inferred(int *emitter, float *dt, uint32_t motionCtx);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`MOV ESI,ECX`) | **High** |
| dt | Stack[0x4] | **High** (caller push `[ebp+8]`) |
| motionCtx | Stack[0x8] | **High** (caller push `[ebp+0xC]`) |
| cleanup | `RET 8` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ decompile)

| Stage | Match | Conf |
|---|---|---|
| Rate accumulate | **Yes** | **High** |
| Countdown early-out | **Yes** | **High** |
| Group count / vector 0xC | **Yes** | **High** |
| Ring flag clear | **Yes** | **High** |
| Empty-name skip to reschedule | **Yes** | **High** |
| Spawn burst + caps | **Yes** | **High** |
| Optional pair + RNG table | **Yes** | **High** |
| Reschedule with ≈1/65535 | **Yes** | **High** (`read_memory` `DAT_00aaa638`) |
| Sole caller FUN_005bc3c0 | **Yes** | **High** |

---

## 5. Machine bytes (selected)

Full body hex (669 B) in raw W26-I append.

Epilogue (`read_memory` near end):
```
5E 83 C4 10 C2 08 00   ; pop esi; add esp,0x10; ret 8
```

Prologue:
```
8B 44 24 04            mov eax, [esp+4]   ; dt*
0F 57 C9               xorps xmm1, xmm1
83 EC 10               sub esp, 0x10
56                     push esi
8B F1                  mov esi, ecx       ; this
```

`DAT_00aaa638` = `80 00 80 37` → float **1.525902e-05** ≈ **1/65535**.

---

## 6. Gaps

- Product English / PDB method name.
- Full emitter layout (vector at `this[3]`, accumulator consumers).
- Nested callee exact thiscall models (decompiler may mis-bind ECX for some `FUN_*`).
- Runtime / bit-exact RNG schedule.

---

## 7. Verdict

CF, ABI, interval/spawn/reschedule semantics, and emitter-domain role are sealed. Nested types + product name residual. → **accept**.

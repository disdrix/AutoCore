# Review A (reconstruction fidelity): `aa_00970b60` SideHost_PushKeyFlag1_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970b60` |
| **VA** | `0x00970b60`–`0x00970b95` (**54 B**) |
| **Canonical name** | `SideHost_PushKeyFlag1_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00970b60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-N) |
| **Counterpart** | `reviews/B_aa_00970b60_SideHost_PushKeyFlag1_Inferred.md` |
| **System** | Side-host key-event push |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (54 B) + `get_function_by_address` + `analyze_function_complete` + sole call-site `read_memory` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Record a key event with **flag 1** onto the optional side-host object (bit-twin of `00970b20`):

1. Key = first dword of ECX key holder.
2. Build `PodU32U8{key, 1}` via `FUN_0043e8f0`.
3. Locked push to `host+0xAC` via `FUN_0043e7f0`.

Sole caller: `NDResourceCache_LookupOrCreate` after alternate-provider miss when `cache+0x6c != 0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00970b60_FUN_00970b60.md` (+ W33-N live seal) |
| Annotated | `docs/reconstruction/raw/aa_00970b60_FUN_00970b60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SideHost_PushKeyFlag1_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970b60.cpp` |
| Function record | `docs/reconstruction/functions/aa_00970b60_FUN_00970b60.md` |
| Named record | `docs/reconstruction/functions/aa_00970b60_SideHost_PushKeyFlag1_Inferred.md` |
| Twin | `aa_00970b20` flag0 body |
| Call site | `read_memory` @ `0075dcd0` (`push [esi+0x6c]; mov ecx, ebp; call`) |

---

## 3. Signature (sealed)

```c
// ECX=keyHolder*; stack host*; RET 0x4
void SideHost_PushKeyFlag1_Inferred(void* keyHolder /*ECX*/, void* host /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| keyHolder | **ECX** | **High** |
| host | Stack formal (`cache+0x6c` at sole site) | **High** |
| container | **host + 0xAC** | **High** |
| flag | **`6A 01`** | **High** |
| cleanup | **`RET 0x4`** | **High** |

---

## 4. Twin seal vs `00970b20`

| Field | flag0 | flag1 |
|---|---|---|
| Entry | `0x00970b20` | `0x00970b60` |
| Size | 54 B | 54 B |
| Flag imm | `6A 00` | `6A 01` |
| Callees | `0043e8f0`, `0043e7f0` | same |
| Host offset | +0xAC | +0xAC |

---

## 5. Gaps (accepted)

- Product English for flag=1 (miss event label).
- Runtime / bit-exact.
- Adapter dual free.

---

## 6. Verdict rationale

Bit-twin + sole call-site + sealed nested push establish the unit. Product flag English residual → **accept-with-gaps**.

# Review A (reconstruction fidelity): `aa_005617c0` WorldObj_SnapshotHostRefsAndUnbind_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005617c0` |
| **VA** | `0x005617c0`–`0x005618a0` |
| **Body** | **224 bytes** (`0xE0`) |
| **Canonical name** | `WorldObj_SnapshotHostRefsAndUnbind_Inferred` |
| **Ghidra name** | `FUN_005617c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-T) |
| **Counterpart** | `reviews/B_aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` |
| **System** | world-object / mode-7 leave snapshot |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs + `get_assembly_context` |
| **Verdict** | **accept** |

---

## 1. Purpose

SwitchHBAI **leave mode 7** helper:

1. Zero snapshot count on caller stack desc.
2. Walk host `*(manager+0x2c)` list `+0x58/+0x5c`.
3. For entries with `+0xc` or `+0x10` equal to object: snapshot push, entry `vtbl+0x28`, host `vtbl+0xc`, compact-remove.
4. `FUN_005614f0(manager, &objSlot, obj)` — defer or unbind.

Snapshot consumed later by `WorldObj_RehomeLinksFromSnapshot_Inferred` (`00560f70`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005617c0_FUN_005617c0.md` (+ W29-T append) |
| Annotated | `docs/reconstruction/raw/aa_005617c0_FUN_005617c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_SnapshotHostRefsAndUnbind_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005617c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005617c0_FUN_005617c0.md` |
| Named record | `docs/reconstruction/functions/aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` |
| Live | decompile ≡ raw CF; epilogue `ADD ESP,14; RET 8` |
| Call site | `005d44d0`: `PUSH snap; PUSH obj; MOV ECX,mgr; CALL` |
| Related dual | W27-O rehome consumer (`00560f70`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of `005614f0` / virtuals.

---

## 3. Signature (sealed)

```c
// thiscall; ECX = manager; stack obj + snapshot*; ret 8; void
void WorldObj_SnapshotHostRefsAndUnbind_Inferred(
    int manager, int obj, int *snapshot);
```

| Formal | Source | Conf |
|---|---|---|
| manager | ECX (`MOV EBP,ECX`); caller EDI=`*(obj+8)` | **High** |
| obj | stack #1 (caller ESI) | **High** |
| snapshot | stack #2 (LEA stack 16 B) | **High** |
| cleanup | `ret 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Zero snapshot count | **Yes** | **High** |
| Match entry+0xc / +0x10 to obj | **Yes** | **High** |
| Grow + push + two virtuals | **Yes** | **High** |
| Compact remove + i-- | **Yes** | **High** |
| Tail FUN_005614f0 | **Yes** | **High** |
| thiscall + ret 8 | **Yes** | **High** |

### ABI seal (call site)

```
; FUN_005d4440 when old mode == 7:
LEA  ECX, [ESP+2Ch]
PUSH ECX              ; snapshot
PUSH ESI              ; obj
MOV  ECX, EDI         ; manager
CALL 005617c0         ; ret 8
```

---

## 5. Gaps / open

1. Product English for mode **7** and host entry type (`+0xc`/`+0x10`).
2. Product names for entry `vtbl+0x28` and host `vtbl+0xc`.
3. Whether caller pre-inits snapshot data/cap (count cleared here; cap 0 grows).
4. Nested dual of `FUN_005614f0`.
5. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/role sealed as mode-7 snapshot producer + unbind tail.

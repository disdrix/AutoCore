# Review A (reconstruction fidelity): `aa_0099c1c0` CNDAssetStringTable_LoadFromStream_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099c1c0` |
| **VA** | `0x0099c1c0`–`0x0099c29b` (**220 B**) |
| **Canonical name** | `CNDAssetStringTable_LoadFromStream_Inferred` (was `FUN_0099c1c0`) |
| **Review date** | `2026-08-04` (W37-I) |
| **Reviewer role** | Reconstruction fidelity (CND string-table stream loader wrapper) |
| **Counterpart** | `reviews/B_aa_0099c1c0_CNDAssetStringTable_LoadFromStream_Inferred.md` |
| **System** | CND asset string table |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + `get_assembly_context`. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: Unserialize W34-J, ResourceCache configure W31-F, caller `FUN_004d73c0`.

---

## 1. Purpose

**Sole retail wrapper** that loads a **CNDAssetStringTable** from a stream into a **temporary host**:

1. If `stream == 0` → return **0** (AL).
2. Construct local host: ResourceCache-family ctor (`FUN_00989cf0`) + vtbl `PTR_FUN_00a983b4`; zero vector triple.
3. Configure: `FUN_00989ef0` with **EDI=cache**, **ECX=0x4000**, stack flag **1**.
4. `AL = CNDAssetStringTable_Unserialize(host, scratch, stream)` (`FUN_0099bba0`).
5. Optional vector tidy (`FUN_00426ed0` + `operator_delete`).
6. Dtor `FUN_00989c10`; return AL.

Does **not** implement string/pyramid parse (owned by Unserialize). Does **not** persist host beyond the call.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0099c1c0_FUN_0099c1c0.md` (+ W37-I append) |
| Annotated | `docs/reconstruction/raw/aa_0099c1c0_FUN_0099c1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDAssetStringTable_LoadFromStream_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0099c1c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0099c1c0_FUN_0099c1c0.md` |
| Named record | `docs/reconstruction/functions/aa_0099c1c0_CNDAssetStringTable_LoadFromStream_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; body `0099c1c0`–`0099c29b`; full 220 B hex; `C2 04 00` |
| Product callee | W34-J plate `CNDAssetStringTable::Unserialize` |
| Caller | `FUN_004d73c0` @ `0x004d74d7` (stage window + RAII pair) |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// one stack arg; RET 4; AL success
uint8_t CNDAssetStringTable_LoadFromStream_Inferred(StreamReader *stream);
```

| Item | Evidence |
|---|---|
| Convention | Epilogue `ADD ESP,0xA8; RET 4` (`C2 04 00`) |
| Null path | `CMP EBX,ESI; JNZ …; XOR AL,AL; JMP epilogue` |
| Configure ABI | `MOV ECX,0x4000; PUSH 1; LEA EDI,cache; CALL 00989ef0` |
| Unserialize | `PUSH stream; PUSH scratch; PUSH host; CALL 0099bba0` |
| Body range | Entry `0099c1c0`, last insn `0099c29b` |
| Xrefs | **1** call site |

---

## 4. Control flow (sealed)

```
if stream == 0: return 0
construct cache + set host vtbl + zero vec
ResourceCache_SetField10AndConfigure(cache, field10=0x4000, flag=1)
ok = CNDAssetStringTable_Unserialize(host, scratch, stream)
if vec_begin: tidy + delete
dtor cache
return ok
```

---

## 5. Gaps (explicit)

- Full host layout (vector vs cache relative placement).
- Meaning of `0x4000` / flag `1` configure pair.
- Caller stage `0x31..0x33` product English.
- Runtime / bit-exact / differential.

---

## 6. Verdict rationale

**accept-with-gaps:** Wrapper ABI/CF, null gate, configure constants, and sole Unserialize call are sealed. Host field map and configure semantics remain open without blocking the load contract.

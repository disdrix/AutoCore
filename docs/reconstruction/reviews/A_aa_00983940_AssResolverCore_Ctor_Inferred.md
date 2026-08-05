# Review A (reconstruction fidelity): `aa_00983940` AssResolverCore_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00983940` |
| **VA** | `0x00983940`–`0x009839af` (**112 B**) |
| **Canonical name** | `AssResolverCore_Ctor_Inferred` |
| **Ghidra name** | `FUN_00983940` |
| **Review date** | `2026-07-29` (W31-G dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-G) |
| **Counterpart** | `reviews/B_aa_00983940_AssResolverCore_Ctor_Inferred.md` |
| **System** | assets / assManager / effect probes |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 112 B) + xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for CS-guarded resolver/probe **core**:

1. Nested **`FUN_00469db0(this)`** (twin of resolver-A member ctor).
2. Zero dwords **`+0x2c/+0x30/+0x34`**.
3. **`InitializeCriticalSection(this+0x38)`**; ready **`*(u8*)(this+0x50)=1`**.
4. Clear process globals **`DAT_00d1ef44/48/50/5c`** (DWORD) and **`DAT_00d1ef58`** (**WORD**).
5. Return `this`.

AssManager B wraps outer `PTR_FUN_00aa1f1c` shell and calls this on **mem+8**. Also stack-used by `FUN_00985010` before `FUN_00984ee0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00983940_FUN_00983940.md` (+ W31-G append) |
| Annotated | `docs/reconstruction/raw/aa_00983940_FUN_00983940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssResolverCore_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00983940.cpp` |
| Function record | `docs/reconstruction/functions/aa_00983940_FUN_00983940.md` |
| Named record | `docs/reconstruction/functions/aa_00983940_AssResolverCore_Ctor_Inferred.md` |
| Live | decompile ≡ raw CF; 112 B hex; caller B path installs outer vtbl then `CALL 00983940` |
| Bytes win | `66 89 3D 58 EF D1 00` → WORD store to `DAT_00d1ef58` |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
AssResolverCore* AssResolverCore_Ctor_Inferred(AssResolverCore* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack after SEH+ebx+esi | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0xC; RET 4` | **High** |
| no vtbl write in body | bytes | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
FUN_00469db0(self)
self[+0x2c..+0x34] = 0
InitializeCriticalSection(self+0x38)
*(u8*)(self+0x50) = 1
DAT_00d1ef44/48/50/5c = 0 (dword)
*(u16*)DAT_00d1ef58 = 0
return self
```

| Stage | Match | Conf |
|---|---|---|
| nested member | **Yes** | **High** |
| triple zero | **Yes** | **High** |
| CS + ready | **Yes** | **High** |
| global clears | **Yes** | **High** |
| WORD @ 00d1ef58 | **Yes** (bytes) | **High** |
| Product English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product class English; outer shell `00aa1f1c` meaning.
2. Semantics of `DAT_00d1ef44..` cluster and triple +0x2c.
3. Nested `FUN_00469db0` product type.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

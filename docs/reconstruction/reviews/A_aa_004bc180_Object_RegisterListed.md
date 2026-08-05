# Review A (reconstruction fidelity): `aa_004bc180` Object_RegisterListed

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc180` |
| **VA** | `0x004bc180`–`0x004bc41c` |
| **Canonical name** | `Object_RegisterListed` |
| **Prior scaffold** | `FUN_004bc180` / `Mission_VOG_DEBUG_STOP` |
| **Review date** | `2026-07-29` (W19-E OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_004bc180_Object_RegisterListed.md` |
| **System** | world object listing / mission notify hooks |
| **Verdict** | **accept-with-gaps** — ABI, CF, COID/handles/types, strings sealed; product English + type labels open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + strings) + `get_function_by_address` / xrefs / callees. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Register `Object*` into a listing manager (`this`):

1. Validate 64-bit COID; hard-fail invalid with log tag `"VOG_DEBUG_STOP"`.
2. Enforce manager mode flags vs object mode char.
3. Soft-reject if already listed.
4. Ensure type-keyed hash bucket; allocate listing handle(s).
5. Optionally notify mission-fail reaction for special types / flag bit5.

Primary evidence against debug-only naming: multi-domain CALL xrefs (spawn, grab, teleport, markers) + structured handle writes + `"already listed"` path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bc180_FUN_004bc180.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_004bc180_FUN_004bc180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_RegisterListed.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bc180.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bc180_Object_RegisterListed.md` |
| Live decompile | `decompile_function` `0x004bc180` — **≡** raw |
| Live bytes | `read_memory` `0x004bc180` length 512 + tail; strings `@0x00a15844`, `@0x009cb4a8` |
| Callees | `CNDHash_LookupByKey`, `FUN_004bc680`, `FUN_004e77d0`, `CVOGReaction_FailMissionNotify`, throws |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Manager in **ECX** | prolog `8B F9` after stack load; Ghidra `__thiscall` |
| Stack arg0 = object* | `8B 75 08` |
| Epilogue | **`ret 4`** (`C2 04 00`) |
| Body range | Ghidra `004bc180`–`004bc41c` |
| Return | `0` success / already-listed; throws `0x80070057` / `0x8007000E` / secondary HR |

```c
int32_t __thiscall Object_RegisterListed(ListingContext* this, Object* obj);
```

### 3.2 Object / manager map — **SEALED**

| Rel | Role | Conf |
|---:|---|---|
| obj `+0x160/+0x164` | COID lo/hi | **High** |
| obj `+0x168` | mode char | **High** |
| obj `+0xdc` | primary handle | **High** (`89 96 DC 00 00 00`) |
| obj `+0xd0/+0xd4/+0xd8` | secondary handles | **High** |
| obj `+0xa8`→`+0x38` | type key | **High** |
| obj `+0x17c` bit5 | extra handle path | **High** |
| mgr `+0xc/+0xd` | mode flags | **High** |
| mgr `+0x18` | CNDHash* | **High** |

### 3.3 Key CF arms — **SEALED**

| Arm | Behavior |
|---|---|
| Invalid COID | log `"VOG_DEBUG_STOP"`; throw `E_INVALIDARG` |
| Mode fail | throw `E_INVALIDARG` |
| Already listed | log `"object %I64d (%d) is already listed"`; return 0 |
| Key | `vtbl+0x208` ? `0x30` : type |
| Bucket miss | `new(0x2c)` + ctor + insert or throw `E_OUTOFMEMORY` |
| Type 0x12 / special 0xe | secondary handle + FailMissionNotify |
| Type 0x14 | FailMissionNotify without that secondary |
| `FUN_005130e0(1)` | tertiary handle |
| Flag bit5 | quaternary handle + FailMissionNotify |

### 3.4 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** raw |
| Bytes | ret4, HRESULT immediates, string ptrs, key `0x30`, size `0x2c` |

---

## 4. Naming

| Name | Status |
|---|---|
| `Object_RegisterListed` | **Structural sealed** (behavior) |
| `Mission_VOG_DEBUG_STOP` | **Incomplete** string-seed — retain as alias only |
| PDB product symbol | **Open** |

---

## 5. Gaps

1. Product English for types `0x12` / `0xe` / `0x14`.
2. Full `ListingContext` / `FUN_004bc680` handle semantics.
3. Meaning of `vtbl+0x208` force-key predicate.
4. Runtime / bit-exact / differential — open.

---

## 6. AutoCore port notes

- Port as **register-if-new** with soft duplicate return, not as a debug-stop API.
- Preserve throw vs soft-return distinction (invalid COID / OOM throw; already-listed returns 0).
- Mission notify is **conditional**, not always-on.

# Review A (reconstruction fidelity): `aa_0096e280` phyBone_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e280` |
| **VA** | `0x0096e280` |
| **Canonical name** | `phyBone_unserialize` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + fresh Ghidra) |
| **Counterpart** | `reviews/B_aa_0096e280_phyBone_unserialize.md` |
| **System** | `physics / phy` (asset I/O) |
| **Dual status** | **Present — CF + PBON tag/version + binary/text dual-path sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unserialize one **phyBone** record from a **PBON** chunk (`tag = 0x50424f4e` = fourCC `PBON`; on-disk little-endian bytes `"NOBP"`), **chunk version 1 only**.

1. Enter chunk scope on the **stoChunkReader** (`param_1` / ECX-style reader).
2. Validate tag + version; on failure log (`phyBone.cpp` lines `0x43` / `0x57`) and return **`0xffffffff`**.
3. On success (binary vs text mode via **`reader+0x4044`**):
   - Read **3× int32** into **`this+0x148 / +0x14c / +0x150`**
   - Read **1× float32** into **`this+0x154`**
   - Ensure / install shared-data object (`FUN_00449dc0`)
   - Nested **`phyBoneSharedData_unserialize(*(this+0xf4))`** (BDAT / TADB hkQsTransform)
   - **`FUN_0096de80`**: copy shared transform into bone local frame (`this+0x4..+0x28`), set **`this+0x140 = -1`**
4. Leave chunk scope if scope flag set; return **OR of field-read / nested error flags**.

Nested TADB carries model-root **hkQsTransform** (quat + translation [+ scale in v2]). Ignoring it misplaces props/doors relative to body XOBB (plate / geo-format notes).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096e280_phyBone_unserialize.md` |
| Annotated | `docs/reconstruction/raw/aa_0096e280_phyBone_unserialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBone_unserialize.cpp` |
| Function record | `docs/reconstruction/functions/aa_0096e280_phyBone_unserialize.md` |
| Nested sibling | `reconstructed-exact/phyBoneSharedData_unserialize.cpp` / `functions/aa_00997540_*` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0096e280` (2026-07-29) — **≡ raw body** |
| Callees | `batch_decompile`: `0x00437050`, `0x00435fe0`, `0x00768760`, `0x00767fd0`, `0x00449dc0`, `0x0096de80`, `0x00769e40` |
| Caller | `FUN_0096b930` (`phySkeleton` unserialize, call site `0x0096ba29`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff. No ledger writes.

---

## 3. Signature (decompiler + callee roles)

```c
// __fastcall-ish: reader in param_1; phyBone* in ESI (this) at entry
// Returns 0 on all-ok (OR of reader status bits), 0xffffffff on bad tag/version
uint phyBone_unserialize(stoChunkReader *reader /* param_1 */);
// this (ESI): phyBone*
```

| Claim | Evidence | Confidence |
|---|---|---|
| Tag `0x50424f4e` (PBON / file `NOBP`) | Immediate compare after EnterChunkScope | **High** |
| Version must be **1** else log + fail | `local_10 == 1` branch; log string | **High** |
| Fail return `0xffffffff` | Both error tails | **High** |
| Success return `uVar2\|uVar3\|uVar4\|uVar5` | OR of 3 int reads + (float \| nested) | **High** |
| `reader+0x4044 == 0` → binary path | Dual callees: `FUN_00437050` / `FUN_00435fe0` | **High** |
| `reader+0x4044 != 0` → text path | `FUN_00768760` ("Expected int32") / `FUN_00767fd0` ("Expected float32") | **High** |
| Three int32 fields `@ this+0x148, +0x14c, +0x150` | Binary + text int readers | **High** (offsets) / **Tentative** (semantic names) |
| One float32 `@ this+0x154` | Text path uses float reader; binary still 4-byte store | **High** (width) / **Probable** (float type from text path) |
| Nested shared `@ *(this+0xf4)` | Call arg to `phyBoneSharedData_unserialize` | **High** |
| Post-copy `FUN_0096de80` | Copies shared `+0xc..+0x30` → bone `+4..+0x28`; `+0x140 = -1` | **High** CF |
| Leave scope `FUN_00769e40` when `local_18` | Standard stoChunk enter/exit SEH pattern | **High** |
| `this` via ESI | Decomp `unaff_ESI`; caller loop sets bone `+0x144` index after call | **High** |

---

## 4. Control flow (sealed)

```
SEH / ExceptionList setup
stoChunkReader_EnterChunkScope(reader)
if (chunkTag != 0x50424f4e)  // PBON
  vog_LogMessage(phyBone.cpp, 0x43, 3, "Invalid TAG unserializing phyBone")
  → fail_exit
if (chunkVersion != 1)
  format "Invalid chunk version (%i) unserializing phyBone"
  vog_LogMessage(phyBone.cpp, 0x57, 3, msg)
  → fail_exit

// version 1 body:
if (reader+0x4044 == 0) {  // binary
  err2 = read_i32_bin → this+0x148
  err3 = read_i32_bin → this+0x14c
  err4 = read_i32_bin → this+0x150
  errF = read_u32_bin → this+0x154   // float bits
} else {                   // text
  err2 = read_i32_text → this+0x148
  err3 = read_i32_text → this+0x14c
  err4 = read_i32_text → this+0x150
  errF = read_f32_text → this+0x154
}
FUN_00449dc0()   // allocate/install default shared-data-like object (EBX-relative)
errN = phyBoneSharedData_unserialize(*(this+0xf4))
errN |= errF
FUN_0096de80()   // copy transform from shared into bone locals; +0x140 = -1
leave_scope_if_needed
return err2 | err3 | err4 | errN

fail_exit:
leave_scope_if_needed
return 0xffffffff
```

### Clean ≡ raw

| Stage | Match |
|---|---|
| Tag / version / fail paths | Yes |
| Four field dual-path reads | Yes |
| Nested shared + post-copy + scope leave | Yes |
| OR return / `0xffffffff` | Yes |

Clean plate is near-raw with type width annotations; CF not rewritten incorrectly.

---

## 5. Layout (this = phyBone*)

```
phyBone
  +0x04 .. +0x28   local transform snapshot (10× float / 40 bytes) filled by FUN_0096de80
  +0xf4            phyBoneSharedData*  (nested BDAT/TADB target)
  +0x140           set to 0xffffffff after copy (invalidation / dirty sentinel — product English open)
  +0x144           bone index — written by caller phySkeleton loop, not this body
  +0x148           int32 field 0
  +0x14c           int32 field 1
  +0x150           int32 field 2
  +0x154           float32 field 3
```

**Product names for the three ints + one float remain open** (likely parent/child/sibling indices + mass or similar — not sealed from this body alone).

### Reader dual-mode (supporting)

| Offset | Role |
|---|---|
| `reader+0x4044` | 0 = binary; non-0 = text chunk mode |

---

## 6. Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| **Caller (1)** | `0x0096b930` @ `0x0096ba29` | `FUN_0096b930` — **phySkeleton** unserialize (tag `0x50534b45` / PSKE family); loops bone vector, calls `phyBone_unserialize`, then `*(bone+0x144) = index` |
| Callee | `stoChunkReader_EnterChunkScope` | Enter PBON scope; fills tag/version locals |
| Callee | `0x00437050` | Binary read **int32** (4 bytes) |
| Callee | `0x00435fe0` | Binary read **4 bytes** (float dest) |
| Callee | `0x00768760` | Text read **int32** (`stoChunk.cpp`, "Expected int32") |
| Callee | `0x00767fd0` | Text read **float32** ("Expected float32" / `sscanf %f`) |
| Callee | `0x00449dc0` | `operator_new(0x90)` + vtable init + refcount; install at `*(EBX+4)` |
| Callee | `0x00997540` | `phyBoneSharedData_unserialize` nested BDAT |
| Callee | `0x0096de80` | Copy shared transform → bone; `+0x140 = -1` |
| Callee | `0x00769e40` | Leave / exit chunk scope |
| Callee | `0x0076cec0` | Format log string |
| Callee | `vog_LogMessage` | Error logging |

---

## 7. Gaps / open questions

1. **Semantic names** of `this+0x148..+0x154` (int×3 + float) — need headers / serialize twin / asset dumps.
2. Exact identity of **`FUN_00449dc0`** product type (0x90 alloc + `PTR_FUN_00aa050c`); relation to `this+0xf4` shared pointer slot (EBX base not fully named here).
3. Meaning of **`+0x140 = -1`** after copy (cache invalidation vs parent link).
4. Formal names for binary/text int/float readers (`FUN_00437050` etc.).
5. Runtime / bit-exact / binary diff open.
6. Clean plate is raw-faithful but not human-renamed (acceptable for dual CF seal).

---

## 8. Verdict

### **accept-with-gaps**

**Accept because:** Fresh Ghidra decompile matches raw; PBON tag + version-1 gate + binary/text dual path + four field offsets + nested shared unserialize + post-transform copy are **High**. Single caller is phySkeleton bone loop. Product field English and `FUN_00449dc0` type name remain open.

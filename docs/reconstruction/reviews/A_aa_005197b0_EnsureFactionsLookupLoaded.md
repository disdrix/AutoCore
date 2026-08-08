# Review A (reconstruction fidelity): `aa_005197b0` EnsureFactionsLookupLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_005197b0` |
| **VA** | `0x005197b0` |
| **Canonical name** | `EnsureFactionsLookupLoaded` |
| **Review date** | `2026-08-04` (WQ-009 residual WQ9R-F) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_005197b0_EnsureFactionsLookupLoaded.md` |
| **System** | factions / client table bring-up |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Ensure-load retail **`tFactions`** rows into the global **CNDHash** at **`0x00b04314`**:

1. Recreate hash (power 4).
2. DB enter → `FUN_007ce550` (xpath **`//tFactions/row`**) → leave.
3. For each source row (stride **`0xc4`**): allocate **0x64** record; copy id; convert two wide strings to MBCS; insert by id.
4. Free temp vector; return.

Consumers: boot `FUN_0094a6a0` InitInstance; lazy gate in `FUN_0051a120` when `DAT_00b04320==0`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005197b0_FUN_005197b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005197b0_FUN_005197b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EnsureFactionsLookupLoaded.cpp` |
| Function record | `docs/reconstruction/functions/aa_005197b0_EnsureFactionsLookupLoaded.md` |
| Live decompile | Ghidra MCP @ `0x005197b0` (2026-08-04) — ≡ raw |
| Bytes | `read_memory` entry + insert tail; call-site context; loader callee decompile string |
| Loader | `FUN_007ce550` string `//tFactions/row` (xpath evidence for table name) |

**Not performed:** `disassemble_bytes`, Launcher, live CE, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No stack args; void return | **High** | call sites; final `RET` |
| Body `0x005197b0`–`0x00519a22` (626 B) | **High** | Ghidra bounds + `CC` pad |
| Hash host ECX=`0x00b04314` recreate power 4 | **High** | `mov ecx,0xb04314; push 4; call FUN_0051d290` |
| DB ctx `*[0x00b0469c]` enter/leave | **High** | same pattern as other Ensure* |
| Loader is `FUN_007ce550` / `tFactions` | **High** | callee string `//tFactions/row`; row size `0xc4` matches loader `operator_new(0xc4)` |
| Source layout id@0, wstr@4, wstr@0x44, stride 0xc4 | **High** | decompile + loader wcscpy targets |
| Out record 0x64: id@0, str@4, str@0x24 | **High** | copy loops + insert |
| Insert `FUN_0051e5d0` ECX=hash, key=id, val=rec, flag0 | **High** | tail: `mov ecx,0xb04314; push 0; push edi; push eax; call` |
| Lazy caller gate `DAT_00b04320==0` | **High** | `FUN_0051a120` site `0051a129` |
| Boot caller InitInstance pack | **High** | `0094afc2` after credits/XP ensures |
| Product English field names for two strings | **Medium** | not labeled in this unit |
| `operator_delete` noreturn | **False warning** | end-of-loop free; continues to SEH restore |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| recreate → enter → load → leave → assert → loop insert → free | **Yes** |
| Decompiler `lpString == 0x40` null test | **Bytes/annotation win** — tests first-string pointer, not imm 0x40 equality as product intent |
| End free “noreturn” | **False** — standard Ghidra hazard |

---

## 5. Call graph (this unit)

**Callees:** `FUN_0051d290`, `FUN_007e1d80`, `FUN_007ce550`, `FUN_007b7df0`, `FUN_007a4480`, `operator_new`, `operator_delete`, `malloc`/`free`, `lstrlenW`, `WideCharToMultiByte`, `PTR_FUN_00af8c9c`, `FUN_0051e5d0`, `FUN_004048e0`, `FUN_004048c0`.  
**Callers:** `FUN_0094a6a0`, `FUN_0051a120`.

---

## 6. Gaps / open

1. Exact product names for the two faction wide-string columns.
2. Full dual of `FUN_007ce550` / `FUN_0051e5d0` / hash field map vs `DAT_00b0431c/20/24`.
3. Whether re-entry after partial fill is safe (Recreate clears).
4. Runtime / bit-exact.

---

## 7. Verdict

**accept-with-gaps** — ensure-load CF + hash host + tFactions xpath + record strides sealed; column English open.

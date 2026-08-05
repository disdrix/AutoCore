# Review A (reconstruction fidelity): `aa_00970910` AssPreloader_ExtBucketFromPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970910` |
| **VA** | `0x00970910`–`0x00970a24` exclusive (**276 B**) |
| **Canonical name** | `AssPreloader_ExtBucketFromPath_Inferred` |
| **Ghidra name** | `FUN_00970910` |
| **Prior scaffold** | `FUN_00970910` / `Named_xml` / `Named_CalleeOf_Named_assPreloader_*` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W38-C) |
| **Counterpart** | `reviews/B_aa_00970910_AssPreloader_ExtBucketFromPath_Inferred.md` |
| **System** | AssPreloader path → extension bucket 0..4 |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Map a C-string path/name to one of five AssPreloader asset buckets by substring match against static extension strings. Primary consumers index parallel tallies at preloader `+0xe8` / `+0xfc`.

**Not** a full path parser, case-folding classifier, or load/IO routine.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` @ `0x00970910` ≡ scaffold raw |
| Bytes | `read_memory` body **276 B**; string lits; `C2 04 00` |
| Strings | `.geo` `0x00a28904`, `.dds` `0x00a2c53c`, `.ogg` `0x00a9d9a4`, `.xml`/`OTHER` `0x00a9eaf0` |
| Empty fallback | `0x00afa2bc` → `0x00a1419b` = `00` |
| Call sites | `get_assembly_context` @ `00970bd6`, `00970c49`, `0097157e`, `009720ea` |
| Parent context | W37-B `AssPreloader_DrainSuccessResultsAndTally_Inferred` |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// stack; RET 4
int AssPreloader_ExtBucketFromPath_Inferred(const char** name_holder);
```

| Formal | Source | Conf |
|---|---|---|
| name_holder | stack0 (`mov eax,[esp+…]; mov eax,[eax]`) | **Confirmed** |
| return bucket | EAX | **Confirmed** |
| RET 4 | `C2 04 00` ×2 exits | **Confirmed** |
| thiscall ECX | **No** — free stack helper | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| SEH + once flag bit0 | **Yes** | **Confirmed** |
| Build 5× basic_string + atexit | **Yes** | **Confirmed** |
| Loop 4 extensions, stride 0x1c | **Yes** | **Confirmed** |
| SSO c_str via capacity > 0xf | **Yes** | **Confirmed** |
| Null haystack → empty | **Yes** | **Confirmed** |
| strstr match → return index | **Yes** | **Confirmed** |
| Past bound → return 4 | **Yes** | **Confirmed** |
| Invented branches | **None** | — |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Indices 0..3 = geo/dds/ogg/xml | **Confirmed** | literal order |
| Default 4 = OTHER bucket | **Confirmed** | callers use as 5-slot index; OTHER not strstr'd |
| Table stride 0x1c | **Confirmed** | MSVC basic_string |
| AssPreloader tally consumer | **High** | 4 call sites + W37-B |
| Product method name | **Open** | no RTTI on VA |
| Suffix-only vs substring | **Open** | CRT strstr anywhere |

---

## 6. Gaps

1. Product/MSVC demangle English.  
2. Whether mid-string `.geo` false-positives are accepted in retail.  
3. Case folding (none in CRT strstr).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, table, bucket semantics, and caller role sealed; product name open.

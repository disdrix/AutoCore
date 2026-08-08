# Review A (reconstruction fidelity): `aa_005190c0` Object_EnsureIntKeyMapAt0x15c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005190c0` |
| **VA** | `0x005190c0` |
| **Canonical name (Ghidra)** | `FUN_005190c0` |
| **Proposed name** | `Object_EnsureIntKeyMapAt0x15c_Inferred` (**High** role; product English absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_005190c0` — chain-of-callers only; **do not promote** |
| **Review date** | `2026-08-04` (OWN-ONLY dual A — WQ9R-E) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_005190c0_Object_EnsureIntKeyMapAt0x15c_Inferred.md` |
| **System** | skills-abilities residual — int-key map ensure for req aggregate |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Lazy-ensure an empty MSVC-like int-key map at `host+0x15C`.**

If the slot is null:

1. `operator_new(0xC)` map header.
2. `FUN_0040f400()` → `operator_new(0x18)` tree sentinel.
3. Stamp sentinel `+0x15 = 1` (is_nil), self-link left/parent/right, `map+8 = size 0`.
4. Store map at `host+0x15C` (null if OOM).

Return `*(host+0x15C)`.

Primary consumers:

- `FUN_0052d450` — clears/rebuilds map, `Map_LowerBoundFindByIntKey` + `FUN_0040ed60` insert with keys from skill/item `+0x34` (requirement aggregation).
- `FUN_0089a260` case 7 — membership probe by `param_2+0x34`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x005190c0` |
| `read_memory` | prologue `0x005190c0`, epilogue `0x00519140` |
| Raw / annotated / clean | `aa_005190c0` three-rep + named clean |
| Related | `FUN_0040f400` sentinel factory; `Object_SharedBase_Dtor` frees `+0x15C` (W29-G) |
| Callers | `FUN_0052d450`, `FUN_0089a260` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
// ECX = host with map slot at +0x15C
IntKeyMapHeader* __fastcall Object_EnsureIntKeyMapAt0x15c_Inferred(void *host);
```

SEH (`LAB_009a363c`). Body **134 B** (`0x005190c0`–`0x00519146` exclusive). `ADD ESP,0x10; RET`.

---

## 4. Layout / callees

| Piece | Detail |
|---|---|
| Map host size | **0xC** |
| `map+4` | sentinel* |
| `map+8` | size (0) |
| `map+0` | not written |
| Sentinel | `FUN_0040f400` → 0x18; is_nil `+0x15` |
| Callees | `operator_new`, `FUN_0040f400` |

Xrefs: **12**. Classification: **worker**.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early out when `+0x15C != 0` | Yes (`CMP/JNZ` via `read_memory`) |
| `new(0xC)` + SEH | Yes |
| Null-new stores null | Yes |
| Sentinel init + size 0 | Yes |
| Return slot | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Lazy ensure of `+0x15C` | **High** | gate + store |
| Map host 0xC; myhead+4; size+8 | **High** | decompile + callers |
| Sentinel is_nil `+0x15` / self-links | **High** | decompile |
| Int-key map (not list) | **High** | `Map_LowerBoundFindByIntKey` consumers |
| Skill/req path consumer | **High** | `FUN_0052d450` structure |
| Product C++ type / demangle | **Tentative** | `_Inferred` |
| `map+0` field meaning | **Tentative** | unwritten |

---

## 7. Gaps / open

1. Product English for host type and map value type (node `+0x10` count in insert path).
2. `map+0` unused vs allocator cookie.
3. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps** — ensure CF/ABI/layout High; product names open.

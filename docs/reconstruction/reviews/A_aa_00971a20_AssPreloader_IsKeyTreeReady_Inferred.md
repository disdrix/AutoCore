# Review A (reconstruction fidelity): `aa_00971a20` AssPreloader_IsKeyTreeReady_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971a20` |
| **VA** | `0x00971a20`–`0x00971b74` (**341 B**) |
| **Canonical name** | `AssPreloader_IsKeyTreeReady_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00971a20` |
| **Review date** | `2026-07-29` (OWN-ONLY W36-E) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00971a20_AssPreloader_IsKeyTreeReady_Inferred.md` |
| **System** | AssPreloader / preload key tree readiness |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 341 B) + `analyze_function_complete` + xrefs + neighbor callees |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

AssPreloader readiness probe for a preload key:

1. Drain pending via `FUN_00971480` (always).
2. Exact-find key in tree map@**+0x10**; miss → **0**.
3. If `recurse==0` or `*(cache@+0x110 + 0x64)==0` → **1**.
4. Else fill deps (`FUN_00744360`); each dep must be shallow-tree-ready **or** cache-present (inlined FindIterator gates); else **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971a20_FUN_00971a20.md` (+ W36-E append) |
| Annotated | `docs/reconstruction/raw/aa_00971a20_FUN_00971a20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_IsKeyTreeReady_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971a20.cpp` |
| Function | `docs/reconstruction/functions/aa_00971a20_FUN_00971a20.md` |
| Named | `docs/reconstruction/functions/aa_00971a20_AssPreloader_IsKeyTreeReady_Inferred.md` |
| Live | decompile ≡ scaffold CF; full 341 B hex; 6 callers; SEH + RET 8 |
| Context | W35-A ProcessKeyRingStep (recurse=0); W21-N FindIterator; W32-L dep fill |

---

## 3. Signature (sealed)

```c
// thiscall ECX=AssPreloader*; stack (key*, char recurse); RET 8; AL 0/1
uint8_t __fastcall AssPreloader_IsKeyTreeReady_Inferred(
    void* preloader, const void* key, char recurse);
```

| Slot | Source | Conf |
|---|---|---|
| ECX preloader | `MOV EDI,ECX` | **High** |
| stack key* | `MOV EBX,[ESP+…key]` | **High** |
| stack recurse | `CMP BYTE [ESP+…],0` | **High** |
| cleanup | **`RET 8`** all paths | **High** |
| return | **AL** 0/1 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH install
FUN_00971480(this)
node = MapLowerBoundExact(this+0x10, key)   // FUN_0043d5e0; out overwrites key slot
if node == *(this+0x14): return 0
if recurse==0 OR *(cache@this+0x110 + 0x64)==0: return 1
deps = empty GuardedVector; FUN_00744360(key, &deps)
for each dep in deps (page map):
  if !IsKeyTreeReady(this, dep, 0)
     AND !cache_present(cache, dep):   // inlined 0044e8c0 + end + value@+0xC
    dtor deps; return 0
dtor deps; return 1
```

| Stage | Match | Conf |
|---|---|---|
| Drain always | **Yes** | **High** |
| Tree find + end miss → 0 | **Yes** | **High** |
| recurse=0 early 1 | **Yes** | **High** |
| cache+0x64 gate | **Yes** | **High** |
| Dep recurse-0 + present OR | **Yes** | **High** |
| RET 8 / AL | **Yes** | **High** |
| Product English | open | **Low** |

### Decompiler noise — sealed as artifact

| Noise | Reality |
|---|---|
| `FUN_0043d5e0()` no args | ECX=map+0x10, EBX=key*, EAX=out_it* |
| `param_2 == *(this+0x14)` after find | key stack slot holds **node\*** post-find |
| Recursive call missing ECX | thiscall ECX=EDI preserved |
| Ghidra bare `undefined FUN(void)` | 2 stack formals + RET 8 |

---

## 5. Gaps / open

1. Product/PDB method English.
2. Full dual of unowned `00971480` / `0043d5e0` / `00744360`.
3. Writers/meaning of `cache+0x64` (ctor zeros; gate only).
4. Runtime / concurrent mutation / bit-exact.

**Verdict:** **accept-with-gaps** — ABI/CF/tree/dep/present sealed; residual product + nested free duals + runtime.

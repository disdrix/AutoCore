# Review A (reconstruction fidelity): `aa_004a0b90` NDSpecialFX_InstantiateFromTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a0b90` |
| **VA** | `0x004a0b90` |
| **Canonical name** | `NDSpecialFX_InstantiateFromTemplate` (inferred) |
| **Prior scaffold** | `FUN_004a0b90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) — OWN-ONLY W16-K |
| **Counterpart** | `reviews/B_aa_004a0b90_NDSpecialFX_InstantiateFromTemplate.md` |
| **System** | `client-fx` / `NDSpecialFX` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA); `FUN_004ba310` decompile for ctor context only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Deep-**instantiate** a new `NDSpecialFX` host from a template:

- Allocate **`0x240`**, construct via **`FUN_004ba310(name)`** (ctor also `strncpy`s name into host `+0xd5`).
- Copy flag bytes/dwords from template.
- Clone optional `+0x60` blob (`0x30`), map `+0x228` payloads (`0x28`), and multiple child lists with **scale** (`param_3`) and **filter** (`param_4`, `-1` = all).
- **Stamp** (`param_5`) written onto spawned instances (`+0x204` path index `0x242`; primary node `+0x8c4`; `+0x210` path index 10 / `+0x28`).

**Caller seal** (dual-reviewed `aa_004a61b0`):

```c
FUN_004a0b90(fx, fx + 0xd5, 1, -1, stamp);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a0b90_FUN_004a0b90.md` (+ 2026-07-29 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_004a0b90_FUN_004a0b90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004a0b90.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a0b90_FUN_004a0b90.md` |
| Live decompile | Ghidra `decompile_function` @ `0x004a0b90` (matches raw CF) |
| Bytes | `read_memory` prologue: SEH + `push 0x240` + `operator_new` |
| Ctor residual | `FUN_004ba310` decompile — name @ `+0xd5`, size consistent with `0x240` host |
| Parent dual | `A/B_aa_004a61b0_NDSpecialFX_LoadFromScriptName` call contract |

---

## 3. Assembly-sealed prologue (`read_memory` @ `0x004a0b90`)

```text
004a0b90  55              push ebp
004a0b91  8BEC            mov  ebp, esp
004a0b93  83E4F8          and  esp, -8
004a0b96  6AFF            push -1
004a0b98  6816109A00      push LAB_009a1016      ; SEH
004a0b9d  64A100000000    mov  eax, fs:[0]
004a0ba3  50              push eax
004a0ba4  64892500000000  mov  fs:[0], esp
004a0bab  83EC60          sub  esp, 0x60
004a0bae  53              push ebx
004a0baf  56              push esi
004a0bb0  57              push edi
004a0bb1  6840020000      push 0x240             ; sizeof host
004a0bb6  E8…             call operator_new
```

Stack formals after prologue: `param_1` template @ `[ebp+8]`, `param_2` name @ `[ebp+0xc]`, scale / filter / stamp follow — matches decompiler arity 5.

---

## 4. Body structure (live ≡ raw)

| Phase | Evidence |
|---|---|
| Ctor host | `new(0x240)` → `FUN_004ba310(param_2)` or 0 |
| Flag copy | stores to host `+0x28,+0xc,+7,+6,+4` from template |
| Unfiltered setup | `if (param_4 == -1) FUN_004a7e30(param_1+0x90)` |
| Blob `+0x60` | `new(0x30)` dword-copy ×12; `blob+0x2c = host` |
| Map `+0x228` | RB walk; clone `0x28`; `FUN_004a7580`; standard successor (`+0x15` color) |
| List `+0x204` | filter `+0x904`; count `*(short*)(+700)*scale`; flag `+0x90d&1`; `FUN_00590800`; stamp `[0x242]` |
| Post `+0x204` | `FUN_0058f610` per clone entry |
| List `+0x21c` | conditional `FUN_0049a120` / `FUN_004b92b0` |
| List `+0x1e0` | heavy deep clone (`FUN_005bdcf0`, chains `0x3e4`, lists, parent remap) |
| List `+0x210` | `new(0x17c)` + `FUN_005b94e0`; POD ×`0x5f`; stamp; flags `\|0x18` |
| List `+0x1ec` | POD `0x138` (`0x4e` dwords) |
| List `+0x1f8` | POD `200` (`0x32` dwords) |
| Temps | `FUN_00439770` sentinel; `FUN_004397f0` temp list destroyed at end |

### Scale / filter formulas (sealed in decompile)

```
// +0x204 path
if (filter == -1 || payload->id904 == filter):
  start = (payload->flags90d & 1) ? (countShort * scale - 1) : 0
  for i in [start, countShort*scale): spawn...

// +0x1e0 path
countShort = (node->ptr8 == 0) ? node->s8f8 : *(short*)(node->ptr8 + 700)
for k in 1..countShort*scale: deep clone...

// +0x210 path
n = (entry->ptr4 == 0) ? 1 : (*(short*)(entry->ptr4 + 700) * scale)
// (decompiler: if ptr4==0 use 1; else if n>0 loop n times)
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Host alloc size **0x240** | **High** | `push 0x240` + ctor field range through `+0xd5+0x104` |
| `FUN_004ba310` is host ctor with name | **High** | thiscall ctor decompile; `strncpy(+0xd5, name, 0x104)` |
| `param_3` multiplies short counts | **High** | `* param_3` on all scaled loops |
| `param_4 == -1` means no filter | **High** | `\|\|` short-circuit on all filtered walks |
| `param_5` stamp on instances | **High** | stores to `+0x8c4`, `piVar5[0x242]`, `piVar11[10]` |
| Multi-list deep clone CF | **High** | live ≡ raw |
| NDSpecialFX domain name | **Probable** | loader tag + dual parent |
| Function returns clone in EAX | **Low / Open** | decompiler `void`; no `mov eax, host` sealed in this pass |
| Product types of child nodes | **Low** | offsets only |
| OOM-safe | **Low** | null host still written |

---

## 6. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + new 0x240 + ctor | **Yes** |
| Flag / blob / map clone | **Yes** |
| Scaled filtered list clones (`+0x204/+0x1e0/+0x210`) | **Yes** |
| POD lists `+0x1ec/+0x1f8` | **Yes** |
| Temp list teardown | **Yes** |
| Explicit `return host` | **No in decompiler** — residual |

Clean is decompiler-faithful with plate documentation; not a modern redesign.

---

## 7. Call graph (this unit)

**Callees (by role):** ctor `004ba310`; map/list helpers `004a7580/004a7670/00439770/004397f0/006759b0/004a6*`; spawns `00590800/005bdcf0/005b94e0/004a6c80/005b8500`; remap `005b0990/004a7210`; sidepath `0049a120/004b92b0/0058f610/004a7e30`.

**Callers:** `NDSpecialFX_LoadFromScriptName` (and any other FX instantiate sites — not fully enumerated in OWN scope).

---

## 8. Gaps / open

1. **Ownership / return:** does clone escape via EAX, global registry, or only side effects? Shared residual with loader dual (`aa_004a61b0`).
2. OOM path writes through null host.
3. Exact product names for `+0x1e0` graph nodes and `0x3e4` chain elements.
4. Semantic meaning of stamp / filter ids (mission? variant? time?).
5. Runtime / bit-exact image diff not run.
6. SEH cleanup paths not fully enumerated (exception-only).

**Verdict:** **accept-with-gaps**

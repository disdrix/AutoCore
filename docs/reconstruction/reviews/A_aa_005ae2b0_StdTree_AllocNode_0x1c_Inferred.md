# Review A (reconstruction fidelity): `aa_005ae2b0` StdTree_AllocNode_0x1c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2b0` |
| **VA** | `0x005ae2b0` |
| **Canonical name** | `StdTree_AllocNode_0x1c_Inferred` |
| **Ghidra name** | `FUN_005ae2b0` |
| **Prior scaffold** | `FUN_005ae2b0` / `Named_CalleeOf_Named_effDeviceEffect_005ae2b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-G) |
| **Counterpart** | `reviews/B_aa_005ae2b0_StdTree_AllocNode_0x1c_Inferred.md` |
| **System** | util / container (MSVC `_Tree` / map) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate and zero-init a 0x1C-byte map/tree node** used by the small-value MSVC `_Tree` family:

1. `operator_new(0x1C)`
2. Zero `node[0]`, `node[1]`, `node[2]` (left / parent / right) when non-null checks pass
3. `*(u8*)(node+0x18) = 1` (color = black)
4. `*(u8*)(node+0x19) = 0` (isnil = false for a bare shell; head ctors flip to 1)

Returns node pointer in **EAX** (decompiler shows `void` / omits `return puVar1` — **call-site sealed**).

**Not** list sentinel (`0x0040fb90` / 0xC circular list), not 0x24/0x30 tree node allocators, not domain device-effect logic despite one historical alias.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| args | none |
| **EAX out** | node* (0x1C) |
| return | plain `C3` |

```c
void *StdTree_AllocNode_0x1c(void);  // EAX = node*
```

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005ae2b0` (2026-07-29) ≡ raw |
| Bytes | `read_memory` 80 B — `6A 1C`, zeros, `C6 40 18 01`, `C6 40 19 00`, `C3` |
| Callers | `get_function_callers` / `get_function_xrefs` — 12 sites |
| Head pattern | `InventoryGrid_ctor_Inferred`, `Skill_GetCategoryCooldownMap`, `FUN_004e7420` |
| Sibling | `FUN_005ae270` (0x24, color@+0x20); dual peer `aa_0058d9c0` (0x30) |
| Raw / clean | `aa_005ae2b0_*`, `reconstructed-exact/FUN_005ae2b0.cpp` |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Callers (xref sealed — multi-system)

| Caller | VA | Role (brief) |
|---|---|---|
| `InventoryGrid_ctor_Inferred` | `0x00572650` | map head @ `this+0x60` |
| `Skill_GetCategoryCooldownMap` | `0x00518d70` | lazy map @ owner+0x6c |
| `FUN_004e7420` | `0x004e7420` | map object ctor |
| `FUN_005adb20` | `0x005adb20` | — |
| `FUN_00572ab0` | `0x00572ab0` | — |
| `FUN_005e12b0` | `0x005e12b0` | — |
| `FUN_0046e310` | `0x0046e310` | — |
| `FUN_00536920` | `0x00536920` | — |
| `FUN_00750260` | `0x00750260` | — |
| `FUN_0075d470` | `0x0075d470` | — |
| `FUN_00970cf0` | `0x00970cf0` | — |
| `FUN_0098ef00` | `0x0098ef00` | — |

### Head init pattern (sealed)

```
head = FUN_005ae2b0();
*(u8*)(head + 0x19) = 1;   // head isnil
*(head+4) = head;          // parent = self
*head = head;              // left = self
*(head+8) = head;          // right = self
// size counter on map host = 0
```

Classic MSVC `_Tree` head/sentinel construction on top of this allocator.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `new(0x1C)` | **Yes** |
| Zero three link dwords | **Yes** (null-checked oddly: `if (puVar1+i != 0)` always true if base non-null) |
| `+0x18 = 1`, `+0x19 = 0` | **Yes** |
| No key/payload init | **Yes** |
| EAX return | **Yes** in clean (raw decompiler omits) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Size **0x1C** | **Confirmed** | `push 0x1C` |
| Links zeroed @ +0/+4/+8 | **Confirmed** | body |
| color @ **+0x18** = 1 | **Confirmed** | `C6 40 18 01` |
| isnil @ **+0x19** = 0 | **Confirmed** | `C6 40 19 00` |
| EAX return | **Confirmed** | callers assign |
| Head factory when post-inited | **High** | multi-caller pattern |
| Value payload 12 B @ +0x0C | **High** (layout) / type **Open** | not written here |
| Decompiler `void` | **Known wrong** | |
| Product name | **Open** | `_Inferred` |
| OOM path writes through NULL | **Confirmed** artifact | same family |

---

## 7. Gaps / open

1. Exact `value_type` per map host (cooldown map vs inventory tree vs others).
2. Whether some sites use the node as a live (non-nil) leaf without extra ctor — insert path likely fills value elsewhere (`FUN_005ae2f0` family is 0x24-oriented).
3. Product / RTTI name.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — size/layout/color/isnil/return sealed High; value domain Open.

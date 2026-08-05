# Review A (reconstruction fidelity): `aa_004b8dc0` FUN_004b8dc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8dc0` |
| **VA** | `0x004b8dc0` |
| **Canonical name** | `FUN_004b8dc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004b8dc0_FUN_004b8dc0.md` |
| **System** | client special-FX host active-flag cascade (weapon / mission-audio adjacent) |
| **Verdict** | **accept** — set-flag + list fanout CF **sealed** |

---

## 1. Purpose

**Edge-triggered set of host active byte `this+0x0B`.**

If `newFlag == *(this+0x0B)`, return immediately (no work).

Else:

1. Store **`*(this+0x0B) = newFlag`**.
2. Walk intrusive list at **`this+0x1E0`**: for each node, `FUN_005bbb90(nodePayload, newFlag, param_3)` (thiscall on node+8 object — see bytes).
3. Walk list at **`this+0x204`**: for each node, `FUN_0058e930(nodePayload, newFlag)`.
4. **If newFlag non-zero (activate):**
   - `FUN_004b7e50(this, 0, 0, 0, 0, 0, 0)` — process attached FX list (sibling dual).
   - `FUN_004b6fc0(this)` — related host follow-up.
   - **return** (skip teardown).
5. **If newFlag zero (deactivate):**
   - Walk list **`this+0x1EC`**: for each entry payload `node[2]`, read TFID-ish fields `@+0x120/+0x124/+0x128` and call stop/cleanup pair  
     `Client_GetMissionCompleteAudioTable(...)` then `FUN_00723b20(...)` (Ghidra name on first is multi-use / overloaded; CF sealed).
   - If **`this+0x1FC != 0`**, walk list **`this+0x1F8`**: for each payload, `FUN_00720d40(p, 1)` then `FUN_007203b0(p, 1)`.

Primary consumers: weapon path `FUN_0056d160` toggles with `(1,0)` on fire-start and `(0,0)` on stop; many other host sites.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004b8dc0_FUN_004b8dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b8dc0_FUN_004b8dc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004b8dc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b8dc0_FUN_004b8dc0.md` |
| Live decompile | Ghidra `batch_decompile` `0x004b8dc0` — body ≡ raw |
| Live bytes | Ghidra `read_memory` `0x004b8dc0` length 128 (entry + early loops) |
| Function meta | body `004b8dc0`–`004b8ec7` |
| Callees | `FUN_004b7e50`, `FUN_004b6fc0`, `FUN_005bbb90`, `FUN_0058e930`, `Client_GetMissionCompleteAudioTable`, `FUN_00723b20`, `FUN_00720d40`, `FUN_007203b0` |
| Callers | 25+ including `FUN_0056d160`, `FUN_0056bce0`, many `0055xxxx` / `005axxxx` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: `this` in **ECX** |
| Args | **`char newFlag`**, **`undefined4 param_3`** (forwarded to `FUN_005bbb90` only) |
| Entry bytes | `8A 44 24 04` load flag; compare `3A 46 0B` vs `this+0x0B` |
| Early-out | `0F 84 F0 00 00 00` — jz near end when equal |

```c
void __thiscall FUN_004b8dc0(void *this, char newFlag, undefined4 param_3);
```

### 3.2 Algorithm — **SEALED**

```
if (newFlag == this->active @ +0x0B) return
this->active = newFlag

for node in list(+0x1E0):  FUN_005bbb90(node->obj, newFlag, param_3)
for node in list(+0x204):  FUN_0058e930(node->obj, newFlag)

if (newFlag != 0):
  FUN_004b7e50(this, 0, 0, NULL, 0, 0, 0)
  FUN_004b6fc0(this)
  return

for node in list(+0x1EC):
  p = node[2]
  stopAudioish(p+0x120, p+0x124, p+0x128, p, 0)   // two callees

if (this+0x1FC != 0):
  for node in list(+0x1F8):
    p = node[2]
    FUN_00720d40(p, 1); FUN_007203b0(p, 1)
```

### 3.3 Layout fields — **SEALED for this unit**

| Off | Role |
|---|---|
| `+0x0B` | **active flag** (byte); edge-trigger compare/store |
| `+0x1E0` | list head (activate notify #1) |
| `+0x1EC` | list head (deactivate audio/FX cleanup) |
| `+0x1F8` | list head (secondary deactivate, gated) |
| `+0x1FC` | gate for `+0x1F8` walk |
| `+0x204` | list head (activate notify #2) |

List walk idiom: `node = *head; while node != head; node = *node` with payload at **`node[2]`** for `+0x1EC` / `+0x1F8`.

### 3.4 Entry machine bytes — **SEALED**

```
8A 44 24 04       mov  al, [esp+4]        ; newFlag
53 56             push ebx; push esi
8B F1             mov  esi, ecx
3A 46 0B          cmp  al, [esi+0x0B]
57                push edi
0F 84 F0 00 00 00 jz   → epilogue
88 46 0B          mov  [esi+0x0B], al
8B 86 E0 01 00 00 mov  eax, [esi+0x1E0]   ; list 1
... walk FUN_005bbb90 ...
8B 86 04 02 00 00 mov  eax, [esi+0x204]   ; list 2
... walk FUN_0058e930 ...
80 7E 0B 00       cmp  byte ptr [esi+0x0B], 0
74 30             jz   → deactivate path
... push zeros; call FUN_004b7e50; call FUN_004b6fc0; return ...
```

### 3.5 Side effects — **SEALED**

- **Idempotent** on same flag.
- Activate path **does not** run deactivate list walks.
- Deactivate path **does not** call `FUN_004b7e50` / `FUN_004b6fc0`.
- `param_3` only observed forwarded into **`FUN_005bbb90`** (not into `0058e930` / teardown).

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| equal-flag early out | Yes |
| store + two notify walks | Yes |
| activate → 004b7e50 + 004b6fc0 + ret | Yes |
| deactivate → 1EC cleanup + gated 1F8 | Yes |

---

## 5. Gaps / open

1. Product type name for host; full node payload layouts.
2. Precise roles of `FUN_005bbb90` / `FUN_0058e930` / `FUN_004b6fc0` / stop callees (sibling duals).
3. Ghidra symbol `Client_GetMissionCompleteAudioTable` at multi-arg stop sites is **suspect overloaded naming** — treat as “table/singleton helper” until those units dual-sealed.
4. Full caller product catalog (25+ sites).
5. Runtime verification not run.

**Verdict:** **accept**

# Review A (reconstruction fidelity): `aa_00480170` SoundQueueSlot_InitTailFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480170` |
| **VA** | `0x00480170` |
| **Canonical name** | `SoundQueueSlot_InitTailFields_Inferred` |
| **Ghidra symbol** | `FUN_00480170` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00480170_SoundQueueSlot_InitTailFields_Inferred.md` |
| **System** | client audio / `CSoundManager` queue slot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf field initializer** for a freelist-popped **sound queue slot** (`~0x160` bytes from `FUN_00480460`).

Authoritative body (live decompile ≡ raw):

1. **`EAX = slot`** (MSVC post-`new`/freelist handoff; decompiler `in_EAX`).
2. Copy **four dwords** from `param_1` (register/`__fastcall` ECX pointer) into:
   - `slot+0x140`, `+0x144`, `+0x148`, `+0x14c`
3. Store **`slot+0x158 = 0xFFFFFFFF`** (sentinel / “unset” handle).
4. Return void (caller treats the same slot pointer as destination for subsequent `strncpy` / field fill).

**Not** an allocator. Parent path `FUN_007258a0` / siblings:

```text
slot = FUN_00480460()           // freelist pop
if slot: FUN_00480170()         // tail init (this VA)
strncpy(slot, path, 0x104)
// copy TFID/type/radii...
FUN_00480350(manager+0x310)     // list insert
```

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00480170_FUN_00480170.md` | ≡ live |
| Annotated | `docs/reconstruction/raw/aa_00480170_FUN_00480170.annotated.md` | ≡ raw |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00480170.cpp` | CF ≡ raw |
| Function record | `docs/reconstruction/functions/aa_00480170_FUN_00480170.md` | scaffold |
| Fresh decompile | Ghidra `decompile_function` / `batch_decompile` @ `0x00480170` | sealed |
| Complete analysis | Ghidra `analyze_function_complete` | leaf; 3 xrefs |
| Parent dual | `A_aa_007258a0_CSoundManager_TryQueueProximitySound_Inferred` | clone chain |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf (no callees) | **Confirmed** | analyze complete |
| Slot `this` via **EAX** | **Confirmed** | `in_EAX`; MSVC freelist→init |
| Writes `+0x140..+0x14c` from 16-byte source | **Confirmed** | four dword stores |
| `+0x158 = -1` | **Confirmed** | literal `0xffffffff` |
| Not `operator_new` / not freelist pop | **Confirmed** | no alloc; contrast `00480460` |
| Used after freelist pop in proximity/UI queue paths | **High** | callers `FUN_007258a0`, `FUN_007252d0`, `FUN_00725a70` |
| Semantic meaning of the four dwords / `-1` | **Medium** | residual (TFID/handle block vs pad) |
| Exact source of `param_1` at each call site | **Medium** | reg-recovered; not sealed from parent duals |
| Product English name | **Probable** | inferred structural |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Copy 4 dwords → `+0x140..+0x14c` | Yes |
| `+0x158 = 0xFFFFFFFF` | Yes |
| No branches / no callees | Yes |

```c
// void SoundQueueSlot_InitTailFields(Slot *eax_slot, uint32_t *src16)
void FUN_00480170(uint32_t *src)  // src in ECX; slot in EAX
{
  *(uint32_t *)(eax + 0x140) = src[0];
  *(uint32_t *)(eax + 0x144) = src[1];
  *(uint32_t *)(eax + 0x148) = src[2];
  *(uint32_t *)(eax + 0x14c) = src[3];
  *(uint32_t *)(eax + 0x158) = 0xFFFFFFFF;
}
```

---

## 5. Callers / callees

**Callees:** none (leaf).

**Callers (3 xrefs):**

| Caller | Site | Role |
|---|---|---|
| `FUN_007258a0` | `0x00725986` | proximity queue clone |
| `FUN_007252d0` | `0x007256b3` | sibling queue path |
| `FUN_00725a70` | `0x00725b1e` | sibling queue path |

---

## 6. Gaps / open

1. Exact 16-byte source at each call site (zeros vs parent TFID).
2. Whether `+0x158 = -1` is a voice handle, list link, or “not playing” sentinel.
3. Runtime not run.

**Verdict:** **accept-with-gaps** — store map and leaf role sealed; source-blob semantics residual.

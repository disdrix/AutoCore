# Review A (reconstruction fidelity): `aa_0040c5c0` Client_UiToastQueue_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c5c0` |
| **VA** | `0x0040c5c0` |
| **Canonical name** | `Client_UiToastQueue_Push` (structural; product/PDB open) |
| **Ghidra name** | `FUN_0040c5c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040c5c0_Client_UiToastQueue_Push.md` |
| **System** | `missions-progression` (shared UI toast; GiveMission path owner) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **growable vector push-back** for **UI toast elements of stride `0x98`**.

`__thiscall(this = toastQueue, pElement)` with **`ret 4`**.

1. Load **begin** `*(this+4)`. If non-null, compute **size** = `(end−begin)/0x98` and **capacity** = `(cap−begin)/0x98` where **end** = `*(this+8)`, **cap** = `*(this+0xC)`.
2. **Fast path** (`begin != 0` **and** `size < capacity`):
   - Copy-construct **one** element at current **end** via `FUN_00404670(end, 1, *pElement)` → inner `FUN_00404710` copies **`0x26` dwords** (`0x98` bytes).
   - Bump end: `*(this+8) = end + 0x98`.
3. **Grow path** (empty or full):
   - `FUN_0040c720(this, &outIt, end, *pElement)` → `FUN_00403980` realloc / 1.5× growth / insert one element; writes iterator to new slot.

**Does not** format text, play audio, grant missions, or open modals. Callers pack a `0x98` POD then push. Prominent mission path: `CVOGReaction_GiveMission` @ `0x00532aeb` after `"Received Mission"` sprintf.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040c5c0_FUN_0040c5c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040c5c0_FUN_0040c5c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UiToastQueue_Push.cpp` (+ legacy `FUN_0040c5c0.cpp`) |
| Function record | `docs/reconstruction/functions/aa_0040c5c0_Client_UiToastQueue_Push.md` |
| Fresh decompile | Ghidra `decompile_function` / `batch_decompile` @ `0x0040c5c0` + callees `0x00404670`, `0x0040c720`, `0x00404710`, `0x00403980` |
| Bytes | `read_memory` 96 B @ entry + 36 B @ exit — stride imul `/0x98`, `ADD EDI,0x98`, **`C2 04 00` ret 4** |
| Xrefs / callers | `get_function_xrefs` / `get_function_callers` / `analyze_function_complete` |
| Call-site ECX | `get_assembly_context` — universal `ADD ECX, 0xE8C8` after entity chain |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall(queue*, element*)` void; **`ret 4`** | **Confirmed** | bytes `C2 04 00` at both exits; one stack push at every site |
| Element stride **`0x98`** | **Confirmed** | decompile size/cap `/0x98`; `ADD …,0x98`; copy loop `0x26` dwords |
| Vector slots: begin `+4`, end `+8`, capacity-end `+0xC` | **Confirmed** | body; `this+0` unused in this VA |
| Fast path: size < capacity → in-place copy + end+=0x98 | **Confirmed** | decompile ≡ asm |
| Full/empty → grow helper `FUN_0040c720` → `FUN_00403980` | **Confirmed** | callees |
| `FUN_00404710` = POD dword copy of element (no deep ctor) | **Confirmed** | `for (i=0x26; i; --i) *dst++=*src++` |
| Parent decompile phantom args on `FUN_00404670` | **Confirmed artifact** | real used formals = `(dst, count, src)`; caller may push 5 dwords + `ADD ESP,0x14` |
| Role = **UI toast queue push** (not mission grant / audio) | **High** | GiveMission packs toast **then** separate audio; craft success toast; objective complete toast |
| Queue `this` = **entity@`char+0xA8` object + `0xE8C8`** | **High** | all sampled sites: load chain then `ADD ECX,0xE8C8` |
| Element layout (caller-owned): text`[0x80]` @+0, color@+0x80, f32@+0x84, f32@+0x88, … | **High** from sibling packing; **not** owned by this VA body |
| Product / PDB name | **Open** | structural `Client_UiToastQueue_Push` |
| Meaning of `this+0` / full queue class | **Open** | only +4/+8/+0xC used here |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin `*(this+4)` | Yes |
| size/cap as `(ptr−begin)/0x98` | Yes |
| Fast path copy + end bump | Yes |
| Grow path `FUN_0040c720` | Yes |
| No invent mission/audio side effects | Yes |
| ABI `ret 4` | Yes (raw scaffold lacked; sealed 2026-07-29) |

### Recovered CF

```c
// void __thiscall Client_UiToastQueue_Push(ToastQueue *this, ToastElement *pElem)
// ToastElement is POD, sizeof == 0x98
void *begin = this->begin;           // *(this+4)
if (begin != NULL) {
  size_t size = (this->end - begin) / 0x98;   // end @ +8
  size_t cap  = (this->cap  - begin) / 0x98;  // cap @ +0xC
  if (size < cap) {
    void *slot = this->end;
    FUN_00404670(slot, 1, pElem);    // FUN_00404710 ×1 dword-copy
    this->end = (char*)slot + 0x98;
    return;
  }
}
FUN_0040c720(this, &tmpIt, this->end, pElem);  // grow + insert
```

---

## 5. Callers (inventory; domain duals own semantics)

| Caller | Site | Role (caller-owned) |
|---|---|---|
| `CVOGReaction_GiveMission` | `0x00532aeb` | "Received Mission" toast after grant insert |
| `CVOGReaction_CompleteObjective` | `0x0053468c` | objective-complete toast |
| `FUN_005307e0` (end-quest sibling) | `0x00530d61` | toast on end path |
| `Client_RecvCraftFromAssemblyKitResponse` | `0x0080b780` | "Item Created!" success toast |
| `FUN_00637de0` Progress toast Action | `0x00637ec8` | requirement progress string toast |
| `FUN_006081b0`, `FUN_007fe8d0`, `FUN_0080db30`, `FUN_00921360`, `FUN_0099c2a0` | various | same queue +0xE8C8 pattern |
| code sites | `0x005adec9`, `0x00650712` | xrefs without named function |

**12 xrefs** total. Shared helper — **not** exclusive to GiveMission; partition owner is GiveMission path for dual residual.

---

## 6. Gaps

1. Product/PDB name for queue type and this push API.
2. Full `ToastElement` field product meanings beyond sealed offsets (floats 2.0 / 1.5, color `0xffeee3d8` common).
3. Owner class of object at entity `+0xA8` holding queue at `+0xE8C8`.
4. Runtime push observation / bit-exact vs EXE.

**Verdict:** CF + ABI + stride + role sealed. **accept-with-gaps.**

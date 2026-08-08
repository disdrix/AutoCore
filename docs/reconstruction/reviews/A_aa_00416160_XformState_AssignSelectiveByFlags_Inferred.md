# Review A (reconstruction fidelity): `aa_00416160` XformState_AssignSelectiveByFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416160` |
| **VA** | `0x00416160` |
| **Canonical name** | `XformState_AssignSelectiveByFlags_Inferred` |
| **Ghidra name** | `FUN_00416160` |
| **Prior scaffold** | `FUN_00416160` / `Named_CalleeOf_Named_phySkeleton_00416160` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00416160_XformState_AssignSelectiveByFlags_Inferred.md` |
| **System** | math / transform-state util |
| **Wave** | WQ9I-G OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Selective assign** of a fixed-layout transform/matrix state from **src → dest**:

```text
// ECX = dest*, stack = src*; ret 4
always copy mid @+0x80..+0xA7 (10 dwords), byte @+0xB8, flags @+0xBC from src
if !(flags&1): copy 16 dwords @+0x00   // 4x4 matrix
if !(flags&2): copy 16 dwords @+0x40   // second 4x4
if !(flags&4): copy 3 dwords @+0xA8
dest.generation @+0xB4 += 1
```

**Full-copy wrapper:** `FUN_00416240` sets `flags=0` then calls this.

**Not** complete dtor `0x00416110`. **Not** phySkeleton-exclusive (scaffold alias is caller-graph only; multi-system xrefs).

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | dest `XformState*` |
| stack | `const XformState* src` |
| return | void; **`ret 4`** (`C2 04 00`) |

Body **218 B** (`0x00416160`–`0x0041623A` exclusive). Leaf (no callees).

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | ≡ raw CF |
| Bytes | `read_memory` 256 B — LEA/copy groups, `TEST cl,1` / `SHR` / `rep movsd`, `add [eax+0xb4],1`, `ret 4` |
| Disasm | `disassemble_function` |
| Callers | 16 xrefs + assembly context (`push src; mov ecx,dest; call`) |
| Wrapper | `FUN_00416240` decompile (clear flags → call) |
| Adjustor | `0x00464853` `add ecx,0x10; jmp` |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Always mid + byte + flags | **Yes** |
| bit0/1/2 gates (set → skip) | **Yes** (`test`/`jnz` before `rep movsd` / tail stores) |
| gen++ at +0xB4 | **Yes** |
| `ret 4` | **Yes** |
| Invented branches | **None** |

---

## 5. Confidence

| Claim | Level |
|---|---|
| thiscall dest/src + ret 4 | **High** |
| Offset map + flag policy | **High** |
| Shared util (not skeleton-only) | **High** (16 multi-system xrefs) |
| Product field English / type name | Open → `_Inferred` |
| Runtime | Open |

---

## 6. Gaps

- Product type name and field English (matrix axis labels, mid block).
- Flag bit semantics in product docs (“invalid src” vs “preserve dest” — behaviorally set=skip).
- Runtime / bit-exact / FPU layout of floats vs dwords.

---

## 7. Verdict

**accept-with-gaps** — selective assign CF/ABI/offsets sealed by bytes + multi-caller sites. Residual: product English, runtime.

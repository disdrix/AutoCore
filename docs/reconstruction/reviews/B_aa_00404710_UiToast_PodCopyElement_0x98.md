# Review B (skeptical / adversarial): `UiToast_PodCopyElement_0x98` / `FUN_00404710` @ `0x00404710`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404710_UiToast_PodCopyElement_0x98.md` |
| **Verdict** | **accept** on CF/stride/ABI/leaf purity; **needs-more-evidence** only on product symbol |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Deep-constructs toast (heap strings / vtables) | **Falsified** — pure `rep movsd`; no calls |
| 2 | Element size is not `0x98` | **Falsified** — `ecx=0x26` dwords; parent vector uses `/0x98` |
| 3 | Null-check is on **src** | **Falsified** — tests **dst** (`edi`); src may crash if null |
| 4 | `__cdecl` / thiscall (ECX dst) | **Falsified** — stack args + **`ret 8`** |
| 5 | This grants missions / plays audio | **Falsified** — memory copy only |
| 6 | Decompiler CF wrong vs bytes | **Falsified** — decomp ≡ `read_memory` |
| 7 | Exclusive craft-response helper | **Overstated** — also used by multi-fill `00404670` on all toast pushes |
| 8 | Product name sealed | **Open** — keep structural / `FUN_*` |
| 9 | Runtime / bit-exact EXE verified | **Open** — static body only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride `0x26×4 = 0x98` | **Confirmed** | Truncated toast / overrun |
| `ret 8` stdcall | **Confirmed** | Stack imbalance |
| Null gate on dst only | **Confirmed** | Ports that null-check src only still match; ports that skip dst check write garbage |
| Leaf purity | **Confirmed** | Low |
| Toast-element role | **High** | Mis-wire as generic memcpy of different width |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// stdcall (dst, src); copies 0x98 POD bytes if dst != null
void UiToast_PodCopyElement_0x98(void* dst, const void* src):
  if dst == null: return
  memcpy(dst, src, 0x98)   // exactly 0x26 dwords; no deep fields

// NOT an owning copy. NOT vector growth. NOT mission grant.
// Callers: FUN_00404670 (×count), FUN_004047a0.
```

---

## 4. Assembly contract (from `read_memory`)

```
00404710  57              push edi
00404711  8b7c2408        mov  edi, [esp+8]
00404715  85ff            test edi, edi
00404717  740d            jz   skip
00404719  56              push esi
0040471a  8b742410        mov  esi, [esp+0x10]
0040471e  b926000000      mov  ecx, 0x26
00404723  f3a5            rep  movsd
00404725  5e              pop  esi
skip:
00404726  5f              pop  edi
00404727  c20800          ret  8
```

Hex: `578b7c240885ff740d568b742410b926000000f3a55e5fc20800`

---

## 5. Falsification notes

### 5.1 “Owning element ctor”

Parent toast dual already sealed: push path uses this for **POD** fill. Any port that `new`s strings inside this VA invents behavior.

### 5.2 Craft-only naming

Scaffold `Named_CalleeOf_…_Client_RecvCraftFr_*` is a **seed alias**. Real fan-in is toast multi-fill for all push callers.

### 5.3 Confusing with grow helpers

Growth / insert live at `FUN_0040c720` / `FUN_00403980`. This leaf never reallocates.

---

## 6. Open questions

1. Retail symbol.
2. Whether `FUN_004047a0` is assign vs fill (sibling dual residual).
3. Bit-exact / runtime — open.

**Verdict:** **accept** on sealed CF, stride, ABI, leaf purity. Reject owning-ctor / mission-side-effect overclaims. Product symbol open.

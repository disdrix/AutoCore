# Review B (skeptical / adversarial): `aa_00833160` ShopVehObject_SwapSelectState_ESI_EDI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00833160` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-D) |
| **Counterpart** | `reviews/A_aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Full object memcpy / assign operator | **Falsified** — only select offsets + nested `+0x510` block |
| 2 | Thiscall ECX=this | **Falsified** — ESI/EDI register pair; ECX used only for callees |
| 3 | Always frees / destroys objects | **Falsified** — no `operator_delete`; pure swap + virtual refresh |
| 4 | Is the FieldBlock copy itself | **Falsified** — **caller** of `FUN_00416240` / `FUN_00416160` |
| 5 | Decompiler repeated writes to `0x13f` are literal product intent | **Rejected as decompiler artifact** — assembly shows distinct byte offsets `+0x4FC/+0x5D0/+0x5DC/+0xBC` |
| 6 | Product name `Drive_i_d_shopveh…` at this VA | **Falsified** — scaffold co-location only; no string/RTTI here |
| 7 | Returns void | **Falsified** — AL 0/1 |
| 8 | Swaps every field including vtbl | **Falsified** — vtbl not swapped; vtbl methods invoked |
| 9 | Physics step / combat | **Falsified** — sole caller is UI list reindex |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI/EDI ABI + null check | **High** | Wrong objects swapped |
| Nested +0x510 three-way | **High** | Xform desync |
| Major dword offsets | **High** | State corruption |
| Byte offset set | **High** (set) / **Med** (micro-order) | Flag glitches |
| Shopveh product English | **Low–Med** (caller graph only) | Naming |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```
// Three-way (assembly):
//   temp = CopyClear(ESI+0x510)
//   Assign(ESI+0x510, EDI+0x510)
//   Assign(EDI+0x510, temp)
// Matches WQ9I-H note on FUN_00833160 as FieldBlock_CopyFrom caller.
// Caller FUN_0083ac90 loads ESI/EDI from host+0x50c[5] during index remap.
```

Live decompile ≡ scaffold overall; byte chain corrected via `get_assembly_context` + `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Port as curated object-state swap for list slot reassignment:
// - inputs: two object pointers (register pair)
// - swap listed dword/byte offsets only
// - three-way swap nested XformState at +0x510 via FieldBlock helpers
// - optional nested pos cross via vtbl+0x1a0 + FUN_0040cf90
// - refresh both via vtbl+0x3bc
// - return 0 if B null else 1
// Do not full-memcpy, do not free, do not treat as thiscall.
// Do not trust decompiler's repeated +0x13f stores as product source.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, FieldBlock swap, and non-full-object semantics. Rejects thiscall/memcpy/dtor/shopveh-as-proven-symbol overclaims; narrows byte-swap micro-order. Residual product English → **accept-with-gaps**.

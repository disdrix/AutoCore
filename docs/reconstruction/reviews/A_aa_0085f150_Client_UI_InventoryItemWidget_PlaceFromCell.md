# Review A (reconstruction fidelity): `aa_0085f150` Client_UI_InventoryItemWidget_PlaceFromCell

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f150` |
| **VA** | `0x0085f150` |
| **Canonical name** | `Client_UI_InventoryItemWidget_PlaceFromCell` |
| **Prior names** | `FUN_0085f150`, `Named_CalleeOf_…_0085f150` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Reviewer role** | Independent reconstruction review (raw ≡ live ≡ entry bytes) |
| **Counterpart** | `reviews/B_aa_0085f150_Client_UI_InventoryItemWidget_PlaceFromCell.md` |
| **System** | `inventory-transfer` (UI sheet layout) |
| **Dual status** | **Present** (first dual seal) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Pixel-place** an inventory item widget from its stored **cell coordinates** and the sheet window’s **origin + pitch**.

```text
// Dual-register ABI (SEALED):
//   ECX = widget*  (item icon)
//   EAX = window*  (inventory sheet host)
//   no stack args; plain RET

if (widget == 0) return;

cellX = widget[+0x498]          // dword index [0x126]
cellY = widget[+0x49c]          // dword index [0x127]
px    = *(window+0x50c) * cellX + *(window+0x504)   // pitchX * X + originX
py    = *(window+0x510) * cellY + *(window+0x508)   // pitchY * Y + originY
widget->vtbl[+0x118](&px)       // SetPosition-like; arg points at {px, py, …}
```

Sole call site: `Client_UI_InventorySheet_AddItemWidget` @ `0x008606b6`  
(`mov ecx,esi; mov eax,edi; call 0x0085f150`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0085f150_FUN_0085f150.md` |
| Annotated | `docs/reconstruction/raw/aa_0085f150_FUN_0085f150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0085f150.cpp` |
| Function record | `docs/reconstruction/functions/aa_0085f150_FUN_0085f150.md` |
| Live decompile | Ghidra `0x0085f150` ≡ raw (`in_EAX` = window) |
| Live bytes | `read_memory` `0x0085f150` length 96 — ends `call [eax+0x118]; pop; add esp,0x10; ret` |
| Parent call | `get_assembly_context` `0x008606b6` — `mov ecx,esi; mov eax,edi; call` |
| Parent dual | `aa_008605b0` documents same formula |

**Not performed:** `disassemble_bytes`, Launcher, visual capture.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | widget* | entry `test ecx,ecx`; caller `mov ecx,esi` (widget) |
| **EAX** | window* | body uses `[eax+0x504..0x510]`; caller `mov eax,edi` (window) |
| stack | none | plain `ret` (`c3`) |
| return | void | no meaningful EAX |

Decompiler labels `__fastcall` + `in_EAX` — correct for dual-register custom convention (not pure thiscall).

---

## 4. Sealed formula (bytes)

```text
// IMUL form (0F AF):
px = pitchX * cellX + originX
py = pitchY * cellY + originY

window+0x504 = originX
window+0x508 = originY
window+0x50c = pitchX   // cell width in pixels
window+0x510 = pitchY   // cell height in pixels

widget+0x498 = cellX    // set by parent from item vtbl+0x250
widget+0x49c = cellY    // page-local Y from parent
```

`read_memory` confirms `imul` + `add` against those exact offsets, then:

```text
lea edx, [esp+4]   // &{px,py,...}
push edx
mov eax, [ecx]     // vtbl
call [eax+0x118]
```

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null widget early-out | **Yes** — `test ecx; jz` |
| Load cellX/Y from widget | **Yes** — `+0x498` / `+0x49c` |
| Window origin/pitch loads via EAX | **Yes** |
| `vtbl+0x118(&pos)` | **Yes** |
| Single caller | **Yes** — only `0x008606b6` |

---

## 6. Confidence

| Claim | Confidence |
|---|---|
| Dual-register ECX=widget EAX=window | **High** |
| Pixel formula | **High** (bytes) |
| Window layout offsets | **High** |
| `vtbl+0x118` = set local/screen pos | **High** CF; English **Probable** |
| Product symbol | **Open** |
| Runtime visual | **Open** |

---

## 7. Gaps

1. Exact structure of the position blob at `esp+4` (2 ints vs more fields — stack frame is `sub esp,0x10`, third dword also written).
2. Whether coordinates are client-local or screen.
3. No multi-caller validation beyond AddItemWidget (none exist).

**Verdict:** **accept-with-gaps**

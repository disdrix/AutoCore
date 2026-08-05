# Review B (skeptical / adversarial): `aa_0085f220` Client_UI_InventoryDropHitTest

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085f220_Client_UI_InventoryDropHitTest.md` |
| **Live re-decompile** | Ghidra MCP 2026-07-29 — body matches 2026-07-23 raw CF; epilogue/call-site bytes override decompiler signature noise |
| **Verdict** | **accept-with-gaps** on ABI + cell/CanPlace math; **reject** “this places the item” / “outs are absolute wire Y” / pure-thiscall signature |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Unit places / commits inventory drop | **Falsified** — returns coords + optional ghost; C2S is DropToGrid; stamp is DropResponse `FUN_00571620` |
| 2 | Decompiler signature `FUN_0085f220(int,int)` is complete | **Falsified** — three stack outs + EAX item + ESI window; **`ret 0x0c`** |
| 3 | `unaff_ESI` is accidental | **Falsified** — callers deliberately set ESI; `[esi+0x56c]` typeHost gate |
| 4 | Out Y is already wire/absolute Y | **Falsified** — outs are **page-local**; DropToGrid re-applies `pageH×pageIdx+cellY` for packet `+0x19`; CanPlace uses absY **internally** |
| 5 | Half-cell math is decompiler fiction | **Falsified** — `mulss` of `0xaaa67c/6ac` and `0xaaa678/6a8` present in body bytes |
| 6 | CanPlace this is the held item | **Falsified** — `mov ecx,[esi+0x56c]` immediately before `call 0x00570840` |
| 7 | Footprint always 1×1 | **Falsified** — loads `item+0x4a0/+0x4a4` and clamps origin |
| 8 | Only one caller (DropToGrid) | **Falsified** — xrefs also `0x0085fc2c`, `0x00861634` |
| 9 | Success implies packet will send | **Falsified** — DropToGrid has further type/trade/busy/store gates |
| 10 | Ready for bit-exact / runtime seal | **Fail** — no live pointer capture; screen-scale globals are BSS |

---

## 2. Decisive sealed contract (attack cannot remove)

```text
// Caller sets EAX=item*, ESI=window*
// stdcall: push outOccupant*, outY*, outX*  (right-to-left) then CALL
// returns AL

if (!item || !outX || !outY || !typeHost=*(window+0x56c)) return 0
if pointer outside grid hit rect: return 0

pageW = typeHost[+0x18] via FUN_0085f1f0(window)
pageH = typeHost[+0x1c] via FUN_0085f1d0(window)
cell  = ratio map + half-cell snap + clamp to page using item[+0x4a0/+0x4a4]
*outX = cellX; *outY = cellY                  // PAGE-LOCAL

absY = pageH * *(i8*)(window+0x564) + cellY
if !CanPlace(typeHost, sizeX, sizeY, cellX, absY, &tfidPair): return 0
// optional: *outOccupant = resolve(tfid) or 0
// optional: update ghost at window+0x574
return 1
```

### Why page-local outs matter

DropToGrid residual already sealed:

```text
wireY = pageH * pageIdx + local_105   // local_105 = this unit's *outY
wireX = local_106                     // *outX
```

If this unit wrote absolute Y, DropToGrid would double-apply page offset. Attack on “hit-test already absolute” **fails**.

### Why CanPlace absY still sealed

Body @ CanPlace prep:

```text
call FUN_0085f1d0          ; AL = pageH
imul byte ptr [esi+0x564]  ; AL = pageH * pageIdx
add  al, cl                ; + cellY
push absY / cellX / sizeY / sizeX
mov  ecx, [esi+0x56c]
call FUN_00570840
```

Same imul site family as DropToGrid pack (`0x00860d41` residual). Cross-unit consistency **survives**.

---

## 3. Decompiler hazards (do not promote)

| Hazard | Reality |
|--------|---------|
| `param_1/param_2` only | Third out + register args |
| `piStack_44 = 0x85f266` | Return-address stack slot pollution |
| `(int)&pbStack_4c` in half-Y compare | Decompiler lost mouseRelY temp; formula still present with correct globals |
| `FUN_0085f1d0(ppiVar17)` fake arg | Helper is EAX=window only (bytes) |
| CONCAT packing for CanPlace sizes | Asm loads plain `edi+0x4a0/+0x4a4` |

Prefer **call-site + helper + CanPlace-prep bytes** over middle-body stack renames.

---

## 4. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall 3 outs + EAX/ESI | **Confirmed** | Broken ports / wrong stack |
| Page-local outs | **Confirmed** | Double page offset on wire |
| CanPlace absY product | **Confirmed** | Page-span / CanPlace false fail |
| Pitch constant values | **Confirmed** | Snap bias wrong at non-default UI scale |
| Runtime scale globals | **Open** | Snap threshold wrong magnitude |
| item `+0x4a0` == InvSizeX | **Probable** | Wrong clamp / CanPlace size |
| typeHost ≡ InventoryGrid | **Probable** | Wrong this for CanPlace |
| Vtable rect identity | **Tentative** | Off-by-one cell at edges |
| Ghost color semantics | **Tentative** | UI only; not wire |

---

## 5. Alternate interpretations

### Minimal reading (favored)

UI helper: map drop pointer → legal footprint origin for current page, gate with shared CanPlace, feed DropToGrid locals and optional drag ghost.

### Competing

1. “General inventory mouse pick” — **weak**: footprint clamp + CanPlace + DropToGrid caller argue **drop**, not free pick.
2. “Writes absolute grid coords” — **refuted** by DropToGrid re-scale of Y.
3. “typeHost is not the grid” — possible binder that **is** layout-compatible with InventoryGrid offsets; CanPlace still treats it as grid this.

---

## 6. Gaps remaining after dual

1. Unnamed callers’ full purposes (type==7 path at `0x0085fbf0`).
2. Live values of `DAT_00d1e818/81c` and scale pair during drop.
3. Proof `+0x4a0/+0x4a4` filled from InvSize at grab time.
4. Pixel-perfect edge cases (cursor on cell border / multi-page cargo).
5. Bit-exact / runtime golden.

**Verdict:** **accept-with-gaps.** Skeptical pass **cannot** remove ABI, page-local outs, or CanPlace absY seal. Overclaims about placement and absolute outs **rejected**.

# Review A residual refresh: `Client_UI_InventoryDropToGrid` (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **VA** | `0x00860a50` |
| **Canonical name** | `Client_UI_InventoryDropToGrid` |
| **Scope** | Dual residual — **drop packet (0x2036/0x20)** pack seal; not full re-dual of store path |
| **Counterpart** | `B_aa_00860a50_Client_UI_InventoryDropToGrid_residual.md` |
| **Prior dual** | `A_aa_00860a50_Client_UI_InventoryDropToGrid.md` / `B_…` (2026-07-29 accept-with-gaps) |
| **Live re-decompile** | Ghidra MCP `0x00860a50`, helpers `0x0085f1d0` / `0x0085f1f0`, pack-site `read_memory` 2026-07-29 |
| **Verdict** | **accept-with-gaps** — prior open **Y formula** + **`ucTypeTo` register** **sealed**; runtime/diff still open |

---

## 1. Residuals closed

| Prior gap | Resolution | Confidence |
|---|---|---|
| Y scale formula (`FUN_0085f1d0 * window[0x159] + local_105`) | **Sealed.** `FUN_0085f1d0` body (bytes @ `0x0085f1d0`): `mov eax,[eax+0x56c]; test; mov eax,[eax+0x1c]`. Pack site @ `0x00860d41`: `call 0x85f1d0` → `imul byte ptr [esi+0x564]` → `add al,[esp+0x0b]` → store Y @ packet `+0x19`. | **High** (asm) |
| `window[0x159]` identity | **Page index byte** at `window+0x564` (`0x159×4`). Matches FindFree band math `yStart = pageH * pageIndex`. | **High** |
| `FUN_0085f1d0` return | **`*(typeHost+0x1c)`** when type host non-null, else 0. Same offset family as InventoryGrid **page height** (`systems/inventory-transfer.md` `+0x1c`). | **High** CF; page-height English **High** via consumers |
| `extraout_EDX+4` type source | **Sealed.** Pack prelude @ `0x00860c38`: `mov edx,[esi+0x56c]`; grid fallthrough keeps EDX; pack end `mov dl,[edx+4]` → packet `+0x1a`. Same host as gate/type checks / Grab `ucTypeFrom`. | **Confirmed** |
| X byte | Unchanged: hit-test `local_106` → packet `+0x18` (`mov [esp+0x28], cl` after opcode dword). | **Confirmed** |
| Opcode / size grid | Unchanged: `mov dword [esp+0x10], 0x00002036`; `push 0x20`. | **Confirmed** |
| COID / global | Unchanged: held item `+0x160/+0x164/+0x168` → `+0x08/+0x0c/+0x10`. | **High** |
| Grid path does **not** write `lQuantity@+0x1c` | Unchanged — only X/Y/type/COID/global/opcode. | **High** |

### Sealed wire Y formula

```text
typeHost = *(UIWindow*)(window + 0x56c)
pageH    = typeHost ? *(i32*)(typeHost + 0x1c) : 0   // FUN_0085f1d0
pageIdx  = *(i8*)(window + 0x564)                    // dword slot 0x159
cellY    = local_105                                 // FUN_0085f220 out
wireY    = (i8)( (i8)pageH * pageIdx + cellY )       // packet +0x19
wireX    = local_106                                 // packet +0x18
ucTypeTo = *(i32/u8*)(typeHost + 4)                  // packet +0x1a
```

Semantic (cross-unit): absolute grid Y = **pageHeight × pageIndex + in-page Y** — same product shape as FindFree page window (`aa_005713a0`) and CanPlace page dim (`aa_00570840` / `FUN_00570840`).

---

## 2. Control flow (unchanged; clean ≡ raw)

| Stage | Match |
|---|---|
| Null host / hit-test fail → 0 | **Yes** |
| Class-4 block when type∉{1,3} | **Yes** |
| Trade type-5 dual rejects | **Yes** |
| Busy soft-return 1 | **Yes** |
| Vendor mode-4 / type-4 store → `0x2027`/`0x40` | **Yes** |
| Else grid `0x2036`/`0x20` + pack | **Yes** |
| `Client_SendSectorPacket` + set busy | **Yes** |
| Fail toast → 0 | **Yes** |

---

## 3. Cross-artifact evidence (this residual)

| Artifact | Role |
|---|---|
| Live decompile `0x00860a50` | Dual opcode CF |
| `read_memory` `0x0085f1d0` | Page-dim load body |
| `read_memory` pack `0x00860c38`–`0x00860d62` | typeHost EDX, imul pageIdx, Y/type stores |
| Sibling `FUN_0085f1f0` | typeHost `+0x18` (width-family companion) |
| `FUN_0085f220` | Writes page-local X/Y outs used as `local_106`/`local_105` |
| Grab `aa_00860e20` | Same type host `window+0x56c→+4` |
| DropResponse `aa_00813730` | Places by `inventoryType@+0x1a` + X/Y |
| Server `InventoryDropPacket.Read` | X@0x18 Y@0x19 Type@0x1a |
| Prior dual A/B 2026-07-29 | Offsets High; formula was Tentative |

---

## 4. Remaining gaps (accept)

1. Runtime cargo/locker multi-page drop capture (pageIdx≠0 → wireY).
2. Differential / bit-exact vs retail EXE (project-wide deferred).
3. Full typed layout of **0x2027 / size 0x40** store path (out of residual scope; CF only).
4. Whether type host **is** InventoryGrid vs UI binder sharing `+0x1c` page dim — **offset use sealed**; English object type **Probable**.
5. Formal C signature (`this` in EAX/ESI) still not portable without callers.

**Verdict:** static dual residual for **drop packet Y formula + ucTypeTo provenance** **sealed**. **accept-with-gaps.**

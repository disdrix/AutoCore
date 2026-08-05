# Review B (skeptical / adversarial): `aa_007b1ec0` NDUIWindow_ApplyXmlNodeAttributes

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b1ec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Server / packet / gameplay logic | No send helpers; only UI field stores, COM attr walk, `vog_LogMessage` | **Falsified** — client UI only |
| 2 | Opens / parses the `.xml` file itself | Body never calls `NDXml_OpenTaggedDocument` / file I/O; assumes a live COM node | **Falsified** — parent `InitFromInterfaceXml` / loaders open docs |
| 3 | `param_2` is a BSTR string | COM vtbl calls (`+0x44` get attributes, length/item walk); null check as pointer | **Falsified type** — COM node; Ghidra BSTR label is wrong |
| 4 | `_DAT_00000000` float math is real | Classic dual-`swscanf` decompiler collapse; destinations are ints/fields/virtuals | **Do not port** — artifact |
| 5 | Always resets the window | Reset gated on `skipReset==0`; Init can pass non-zero; factories pass `0` | **Partial** — flag is real |
| 6 | INCLUDE is string-only local | After path convert, **`(*this)+0x3a4`** virtual call; also saves/restores `DAT_00d1794c` | **Survives** as nested load hook |
| 7 | Unknown attributes are ignored | Terminal **`vtbl+0x3a8`** with attr/value | **Falsified “ignore”** — subclass extension point |
| 8 | `g_flOne` / `DAT_00d1e818` product-specific | Shared float `1.0f` @ `0x00a0f2a0`; BSS zeros at `0x00d1e818/1c` in static image | **Value sealed / names pool-generic** |
| 9 | Only one caller | Five UNCONDITIONAL_CALL xrefs (Init + four sibling factories) | **Do not undercount** |
| 10 | Name invents “ApplyXmlNodeAttributes” | Plate + attr cascade + `NDUIWindow.cpp` path; RTTI `CNDUIWindow` | **Survives** as registry canonical |

---

## 2. Cross-check: live decompile ≡ scaffold

Live `decompile_function(0x007b1ec0)` (2026-07-29) matches raw/annotated/clean control structure:

- SEH + `if (param_4==0)` free/zero/`g_flOne` block
- Null `param_2` → post path
- Attr loop with same wide names (`TOOLTIP` … `SOUND` + default `+0x3a8`)
- Log strings + `vog_LogMessage(NDUIWindow.cpp)`
- Epilogue free BSTR / restore ExceptionList

**No material drift** vs 2026-07-23 scaffold. Clean file still embeds decompiler noise (`_DAT_00000000`, garbage L"…" literals) — **not** a second product behavior.

Prologue/epilogue bytes:

```text
007b1ec0: 6A FF 68 FF 1C 9B 00 64 A1 ... 8B F1   ; SEH, this→ESI
007b3054: C2 0C 00                               ; RET 12
```

---

## 3. ABI adversarial check

| Check | Result |
|---|---|
| `RET 0x0C` ⇒ 3×4B stack args | **Holds** |
| Callers push three dwords then `MOV ECX,this` | **Holds** (all five sites) |
| Factory pattern `PUSH node; PUSH 0; PUSH 0` | **Holds** — full reset + no path store |
| Init pushes path + flag | **Holds** — `interfacePath` / `skipReset` semantics |
| Return value meaningful | **Reject** — void; no EAX consumer pattern required |

---

## 4. Attribute table adversarial notes

| Risk | Mitigation |
|---|---|
| Missed attributes in cascade | Nested `wcscmp` is exhaustive to default `+0x3a8`; string anchors present in image |
| Bool compare uses wrong BSTR | `MOVEABLE`/`STICKY`/… compare value to `L"true"`; false leaves flag clear (`==0` result) | 
| `TEXT_ALIGN` numeric path uses wrong stack slot | Decompiler confuses temps; **named** path (`left`/`center`/`right`/`justify`) is solid; numeric fallback range-check 0..3 still gated on parse success |
| TRIM_COLOR R/G/B/A order | Explicit `wcscmp` chain R→G→B→A; negative → `DAT_00d1e7d0`..`d3` defaults |
| Overclaim helper English | Helpers left as `FUN_*` — **correct** for own-VA dual |

---

## 5. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI-only attr applicator | **High** | Wrong subsystem ownership |
| ABI / `skipReset` | **High** | Double-free or skipped defaults |
| INCLUDE / unknown vtbl hooks | **High** | Nested XML / subclass attrs broken |
| Field English for every offset | **Low–Med** | Doc-only; layout still byte-accurate |
| COM slot product names | **Med** | Interop docs only |
| Porting `_DAT_00000000` | **Reject** | Corrupt state |

---

## 6. Surviving contract for AutoCore

```
// Client-only. thiscall, RET 0x0C.
// NDUIWindow_ApplyXmlNodeAttributes(this, msxmlNode, interfacePathOrNull, skipReset):
//
// if (!skipReset):
//   free known string/table slots; zero layout flags;
//   copy DAT_00d1e818/81c into this+0x1c0/0x1c4;
//   this float scales [0x74]/[0x76] = 1.0f;
// if (node):
//   for each attribute name (skip names starting with '#'):
//     dispatch sealed wide-name table → vtbl setters / fields / helpers;
//     INCLUDE → vtbl+0x3a4(path); unknown → vtbl+0x3a8;
// if (!skipReset):
//   vtbl+0x10c(); cache vtbl+0x120() pair at this+0x168/0x16c;
//   if path: replace this+0x284 C-string.
//
// Does NOT open files. Parents: InitFromInterfaceXml + child factories (00792b50 family).
// Server / packets: none.
```

Byte offs cited above use dword index×4 where Review A uses bracket notation (`[0x5a]`→`+0x168`, `[0xa1]`→`+0x284`, `[0x70]`→`+0x1c0`).

---

## 7. Open questions (residual)

1. Product names of helper `FUN_007a*` color/geo/text loaders (separate duals).
2. Exact MSXML interface IDs for node/map methods at vtbl `+0x44` / `+0x30` / item get.
3. Whether any caller passes `skipReset!=0` besides Init’s second argument path.
4. Runtime: INCLUDE recursion depth / `DAT_00d1794c` nesting.
5. Optional clean-up of scaffold noise without behavior change.

**Verdict:** Adversarial pass rejects server/file-open/BSTR overclaims and decompiler float garbage; sealed attr/ABI contract holds. **accept-with-gaps.**

# Independent adversarial spot-check — W38-H duals `0x00456780` + `0x0074ce60`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** W38-H dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | W38-H OWN pair (dword vector resize + phyBoundingBox unserialize) |
| **Units** | `0x00456780` `StdVector_DwordResize_EcxCount_EdxVec_Inferred`; `0x0074ce60` `phyBoundingBox_Unserialize` |
| **Tools** | Ghidra MCP `decompile_function`, `read_memory`, `get_function_callers`; artifact read-through |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00456780-0074ce60-w38h-report.md` |
| `docs/reconstruction/reviews/A_aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0074ce60_phyBoundingBox_Unserialize.md` |
| `docs/reconstruction/reviews/B_aa_0074ce60_phyBoundingBox_Unserialize.md` |

### Artifacts

| Kind | `aa_00456780` | `aa_0074ce60` |
|---|---|---|
| Raw (+ W38-H append) | `docs/reconstruction/raw/aa_00456780_FUN_00456780.md` | `…/aa_0074ce60_FUN_0074ce60.md` |
| Annotated | `…/aa_00456780_FUN_00456780.annotated.md` | `…/aa_0074ce60_FUN_0074ce60.annotated.md` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00456780.cpp` | `…/FUN_0074ce60.cpp` |
| Clean named | `…/StdVector_DwordResize_EcxCount_EdxVec_Inferred.cpp` | `…/phyBoundingBox_Unserialize.cpp` |
| Function named | `docs/reconstruction/functions/aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` | `…/aa_0074ce60_phyBoundingBox_Unserialize.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `decompile_function(0x00456780)` | Live ≡ raw scaffold: size via `(end−begin)>>2`, grow/shrink split, formals `param_1`/`param_2` omit fill; grow collapsed to `FUN_00456960(end)` only |
| `decompile_function(0x0074ce60)` | Live ≡ raw: SEH, tag `0x42424f58`, v1/v2, `unaff_EBX` reader, xz `ABS(SQRT(…))` → `param_1[4]`, return `(-1 < status) - 1`; `readF32Array` destinations elided |
| `read_memory` @ `0x00456780` (128 B) | Full 117 B body + `CC` pad; hex ≡ raw W38-H append |
| `read_memory` @ `0x0074ce60` / `@0x0074d0a0` | Prologue SEH + `MOV ESI,ECX`; epilogue `ADD ESP,0x24; RET` (`C3`) + `CC` pad |
| `read_memory` array LEAs (v1+v2) | Stream dest order **`+0x14` → `+0x20` → `+0x00`** (see finding) |
| `read_memory` tag compare region | bytes `58 4F 42 42` = LE `'BBOX'` / `0x42424F58` |
| `read_memory` pool shrink site `@0x009860c0` | `PUSH 0`; `LEA ECX,[EAX-1]`; `CALL 00456780` |
| `read_memory` clear site `@0x004665c8` | `PUSH EBP`; `XOR ECX,ECX`; `MOV EDX,ESI`; `CALL 00456780` |
| `get_function_callers(0x00456780)` | **35** distinct parent functions (matches dual) |
| `get_function_callers(0x0074ce60)` | **5**: `gfxGeometryPiece_Unserialize`, `FUN_00765740`, `FUN_0095ef50`, `FUN_0095f560`, `FUN_00960f80` (exact match) |

---

## Live bytes vs dual claims

### `0x00456780` body (117 B / `0x75`)

Live `read_memory` body hex (pad excluded; ≡ raw W38-H append):

```
8b420485c056750433f6eb088b72082bf0c1fe023bf1733485c075158b420833f6502bce8d44240ce8b30100005ec204008b72082bf08b4208c1fe02502bce8d44240ce8980100005ec2040085c07421578b7a088bf72bf0c1fe023bce731153578d048850528d5c241ce871feffff5b5f5ec20400
```

Independent CALL/RET resolution from body:

| Site | Op | Target / form |
|---|---|---|
| `0x004567a8` | `E8` | → **`0x00456960`** (grow/InsertN) |
| `0x004567ae` | `C2 04 00` | **RET 4** |
| `0x004567c3` | `E8` | → **`0x00456960`** (grow) |
| `0x004567c9` | `C2 04 00` | **RET 4** |
| `0x004567ea` | `E8` | → **`0x00456660`** (shrink/erase) |
| `0x004567f2` | `C2 04 00` | **RET 4** |
| after `0x004567f5` | `CC…` | pad |

| Claim | Live evidence | Verdict |
|---|---|---|
| Exclusive range `00456780`–`004567f5` (117 B) | len=117; three `C2 04 00`; pad `CC` | **Confirmed** |
| Entry: begin from **`[EDX+4]`** | `8B 42 04` | **Confirmed** (EDX=vec) |
| Size `(end−begin)>>2` | `SUB` / `SAR ESI,2` | **Confirmed** (dword stride) |
| Grow when `size < n` (`CMP ESI,ECX` / `JAE`) | `3B F1 73 34` | **Confirmed** (ECX=newCount) |
| Grow args: `SUB ECX,ESI` count; `LEA EAX,[ESP+0xC]` &fill; push end | both empty and non-empty grow paths | **Confirmed** (bytes win over decompiler) |
| Shrink: `LEA EAX,[EAX+ECX*4]`; push end/vec; call erase | `8D 04 88 50 52` + `E8` → `00456660` | **Confirmed** |
| **RET 4** (not bare RET / not RET 8) | three `C2 04 00` | **Confirmed** |
| Distinct from `0044a380` / `004367f0` | this body never uses EAX as count; cleanup is RET 4 not RET 8 | **Confirmed** (family split stands) |

Call-site ABI samples:

| Site | Live pattern | Dual claim |
|---|---|---|
| Pool freelist shrink `0x009860c0` | `6A 00` fill; `8D 48 FF` = size−1 into ECX; `E8` → `00456780` | **OK** |
| Clear `0x004665d1` | `55` (push EBP fill); `33 C9`; `8B D6`; call | **OK** |

### `0x0074ce60` body (596 B / `0x254`)

| Claim | Live evidence | Verdict |
|---|---|---|
| Exclusive range `0074ce60`–`0074d0b4` (596 B) | end `83 C4 24 C3` @ `0074d0b0`–`0074d0b3`; pad `CC` | **Confirmed** |
| SEH `LAB_009b1ab3` + `SUB ESP,0x18` | prologue `6A FF 68 B3 1A 9B 00` … `83 EC 18` | **Confirmed** |
| **ECX = bbox** (`MOV ESI,ECX`) | `8B F1` after frame setup | **Confirmed** |
| **EBX = reader** | decompiler `unaff_EBX`; callees/callers set EBX; body uses `[EBX+0x4044]` / `[EBX+0x402c]` | **Confirmed** |
| Tag **`'BBOX'`** = `0x42424F58` | compare immediate bytes `58 4F 42 42` | **Confirmed** |
| Version 1 / 2 only; else log + −1 | decompile CF + dual string lines `0x7e` / `0x9c` | **Confirmed** |
| Binary/text via reader `+0x4044` | `83 BB 44 40 00 00 00` (`CMP [EBX+0x4044],0`) | **Confirmed** |
| Success from reader `+0x402c` → `0` / `−1` | decompile `return (-1 < iVar2) - 1` | **Confirmed** |
| Extent `@+0x10` = `abs(sqrt(dx²+dz²))` xz-only | SSE: `[ESI+0]` & `[ESI+8]` vs `[ESI+0x20]` & `[ESI+0x28]`; `SQRT`/`FABS` → `[ESI+0x10]` | **Confirmed** |
| v1 bool `@+0x2C` from scalar≤0; v2 stream-read bool first | decompile + `LEA EDI,[ESI+0x2C]` before v2 bool helpers | **Confirmed** |
| Three `readF32Array` count=3 destinations set | LEAs present both versions | **Confirmed as a set** |
| Stream order `+0x00`, then `+0x14`, then `+0x20` | Live LEAs: **`+0x14` → `+0x20` → `+0x00`** (both v1 and v2) | **Falsified (order)** |

#### Stream-order finding (material)

v2 tail (and the matching v1 path) at live LEAs:

```text
LEA ECX, [ESI+0x14]   ; first  float3 → +0x14
MOV EAX, 3
CALL stoChunkReader_readF32Array
LEA EDI, [ESI+0x20]   ; second float3 → +0x20
…
MOV ECX, ESI          ; third  float3 → +0x00
…
LEA EAX/EBP, [ESI+0x0C]  ; then scalar f32
```

Dual report / raw append / clean named list destinations as **`+0x00`, `+0x14`, `+0x20`** (A→B→C). That is the **wrong stream order**. Field **set** is correct; **fill sequence from the chunk stream** is B→C→A offsets (`+0x14` → `+0x20` → `+0x00`).

Impact: a port that reads three consecutive float3s into A then B then C will mis-assign stream data. Extent math still uses A.xz/C.xz after fill, so wrong order also corrupts extent.

---

## Confirmed claims

### `0x00456780` — `StdVector_DwordResize_EcxCount_EdxVec_Inferred`

| Claim | Verdict |
|---|---|
| Worker MSVC-style `vector<uint32_t>::resize(n, value)` | **Confirmed** |
| Layout begin `@+4` / end `@+8`; stride 4 | **Confirmed** |
| ABI **EDX=vec / ECX=n / stack fill / RET 4** | **Confirmed** |
| Grow → `FUN_00456960`; shrink → `FUN_00456660` | **Confirmed** (live targets) |
| Decompiler omits fill + grow count — dual correctly privileges bytes | **Confirmed** |
| Not merge with `0044a380` (EAX-count) or `004367f0` (RET 8) | **Confirmed** |
| 35 parent functions incl. pool freelist `00986070` | **Confirmed** via callers |
| Name `_Inferred` structural; reject gfxBody-only scaffold | **Appropriate** |
| Clean named models grow/shrink CF + plate ABI | **Confirmed** (documentary; not bit-exact) |
| Dual A/B both **accept** | **Appropriate** |

### `0x0074ce60` — `phyBoundingBox_Unserialize`

| Claim | Verdict |
|---|---|
| Worker phyBoundingBox sto-chunk unserialize (`phyBoundingBox.cpp`) | **Confirmed** (path + strings) |
| ABI **ECX=bbox / EBX=reader / int 0|−1 / bare RET** after SEH teardown | **Confirmed** |
| Tag `'BBOX'`; versions 1–2 only | **Confirmed** |
| Field map `+0x00/+0x0C/+0x10/+0x14/+0x20/+0x2C` roles | **Confirmed** (layout) |
| xz-only extent recompute; not full 3D radius | **Confirmed** |
| v1 derive bool from scalar≤0; v2 stream bool first | **Confirmed** |
| 5 callers including gfxGeometryPiece embed `@piece+0x24` | **Confirmed** |
| Reject sole “post-effect hook” identity | **Appropriate** |
| Name product-anchored **High** | **Appropriate** |
| Stream order of three float3 reads as A→B→C (`+0`/`+0x14`/`+0x20`) | **Falsified** — live order B→C→A |
| Clean success path bit-exact return from `+0x402c` | **Documentary only** (clean stubs `return 0` with comments) — dual already flags runtime/bit-exact |

---

## Adversarial attacks (this pass)

| # | Attack | Result |
|---|---|---|
| 1 | `00456780` is thiscall with ECX=vec | **Fails** — entry `[EDX+4]`; callers load EDX=vec |
| 2 | newCount is stack-only; ECX scratch | **Fails** — `CMP ESI,ECX` before stack count load; callers put n in ECX |
| 3 | RET 8 / bare RET | **Fails** — three `C2 04 00` |
| 4 | Element size ≠ 4 | **Fails** — `SAR 2` / `LEA [reg+reg*4]` |
| 5 | Grow ignores insert count (decompiler) | **Fails** — `SUB ECX,ESI` both grow entries |
| 6 | Same ABI as `0044a380` | **Fails** — opposite vec/count registers + different grow/shrink callees |
| 7 | `0074ce60` is only a gfx post-effect hook | **Fails** — product path + 4 non-gfx callers |
| 8 | Tag not BBOX / single version | **Fails** — tag immediate + v1/v2/error |
| 9 | Reader is stack formal only (no EBX) | **Fails** — EBX convention + callers |
| 10 | Extent is full 3D radius | **Fails** — only x and z terms in SSE |
| 11 | v1 and v2 identical bool policy | **Fails** — v2 reads bool first; v1 derives |
| 12 | Always return 0 on leave | **Fails** — status at `reader+0x402c` |
| 13 | Dual body hex wrong vs image (`00456780`) | **Fails** — 117 B identical |
| 14 | Dual stream order A→B→C for float3s | **Holds as dual error** — live LEAs B→C→A |
| 15 | Caller counts inflated | **Fails** — live 35 / 5 match dual |

---

## Residual gaps (honest)

### Already flagged by dual (still open; not dual failures)

1. Product/PDB English for resize STL mangled name; float3 product labels (min/max/center) for bbox.  
2. Unowned grow/shrink callee duals (`00456960` / `00456660`) and full reader helper dual ownership.  
3. Full SEH cleanup path bit-exact for bbox.  
4. Runtime / differential / Launcher (explicitly excluded).  
5. Terminal coverage false.

### New / material from this ADV pass

6. **`0074ce60` stream order of the three `readF32Array(3)` calls is `+0x14`, `+0x20`, `+0x00`**, not `+0x00`, `+0x14`, `+0x20` as stated in dual report, raw W38-H append, A review destination list, and clean named `phyBoundingBox_Unserialize.cpp`.  
7. Clean named success path is a documentary stub (`return 0`) — acceptable only if ports follow dual status rule, not the stub literally.

---

## Pass / fail

### `aa_00456780` — **PASS**

- Dual quality: **solid**.  
- Verdict retention: keep **`accept`**.  
- Action: **none**.

### `aa_0074ce60` — **PASS-WITH-FINDINGS**

- Dual quality: **strong on ABI / tag / version / extent / v1–v2 bool policy / callers**; **weak on float3 stream order** (sealed incorrectly in multiple artifacts).  
- Verdict retention: keep **`accept`** for identity + core CF, but treat stream order as **required fix** before port.  
- Action (recommended, not performed by this verifier):  
  1. Correct clean named read sequence to `+0x14` → `+0x20` → `+0x00` (then scalar `@+0x0C`, extent, bool rules unchanged).  
  2. Amend raw W38-H append + dual report destination wording to match LEAs.  
  3. Optionally note decompiler elision of destinations as the root of the dual order error.

### Pair summary

| VA | Dual quality | Verdict retention | Action |
|---|---|---|---|
| `0x00456780` | **PASS** | keep **accept** | none |
| `0x0074ce60` | **PASS-WITH-FINDINGS** | keep **accept** (with stream-order fix) | fix float3 stream order in clean/raw/report |

**Overall W38-H pair: PASS-WITH-FINDINGS.** Resize helper fully seals under independent re-verify. Bounding-box unserialize core identity and most sealed facts stand; one material stream-order mis-seal must be corrected before AutoCore asset-load port.

---

## Process notes

- Independent of W38-H dual author; no parent ledger / WORK_QUEUE / COVERAGE_LEDGER / ACTIVE_WORK / CHANGE_LOG / RESUME edits.  
- No `disassemble_bytes`; seal via `decompile_function` + `read_memory` + callers.  
- No dual artifact rewrite in this pass (findings only).  
- Spot-check tools match dual hygiene (bytes win over decompiler formals).

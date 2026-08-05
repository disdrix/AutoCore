# Review B (skeptical / adversarial): `aa_00813730` Client_RecvInventoryDropResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813730` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh — ABI + dispatch) |
| **Counterpart** | `reviews/A_aa_00813730_Client_RecvInventoryDropResponse.md` |
| **Prior dual** | `aa_00813730_skeptical_review.md` (2026-07-23; opcode Tentative — **superseded**) |
| **Live evidence** | Ghidra decompile body `0x00813730` + dispatch `0x00815710`; xrefs; `read_memory` prologue + call site `0x008159be` |
| **Scratch** | `tmp/a_00813730.md` |
| **Verdict** | **accept-with-gaps** on CF + dispatch/ABI/base fields; swap/concat depth + runtime still open |

---

## 1. Claims under attack (post-residual)

| # | Claim | Attack result (2026-07-29 residual) |
|---|---|---|
| 1 | Body proves opcode is always `0x2037` | Still **body-absent** — only special-cases `0x203b`. **Dispatch Confirmed** externally: `case 0x2037`/`0x203b` → this VA; sole xref call `0x008159c2`. |
| 2 | Server success always stamps grid | **Falsified** — client place can fail → toast `"Dropping failed trying to add to inventory"`. |
| 3 | Type map labels fully sealed | **CF High**; cargo/locker English labels High (wire RE); trade/other **Probable**. Hardpoint type **2** intentionally invalid here. |
| 4 | Non-swap always calls Place | **Overstated** — skip when already at (X,Y) via `FUN_00571b60` + vfuncs `+0x250/+0x254`. |
| 5 | Portable cdecl `(client, packet)` | Formals unused — **register ABI Confirmed**: call site `MOV EBX,ESI; MOV EAX,EBP` + prologue `MOV ESI,EAX` / `CMP [EBX],0x203b`. Portable form still **Tentative**. |
| 6 | Clean finished exact / bit-for-bit | **Overstated** — scaffold-faithful CF; runtime/diff open. |
| 7 | Swap/concat retail semantics sealed | **Not sealed** — branch structure High CF; qty/vfunc product names **Probable**. |
| 8 | AutoCore Write covers full wire | **Falsified for stack-merge** — omits occupant `@+0x28` and concat `@+0x38`. Base non-swap plate matches. |
| 9 | Opcode seal is plate folklore | **Falsified 2026-07-29** — live PacketDispatch + sole xref + body `CMP [EBX],0x203b` bytes. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Early-out `*packet == 0x203b` | **High / Confirmed** | Wrong shared-slot handling |
| Dispatch **0x2037** → this VA | **Confirmed** | Dead / wrong handler |
| Sole caller PacketDispatch @ `0x008159c2` | **Confirmed** | Hidden alternate entry |
| EAX=client / EBX=packet | **Confirmed** | Silent no-op / crash |
| Success `@+0x22` fail toast | **High** | Sticky fail UX |
| Type switch 1/3/5/6 + invalid default | **High** | Wrong inventory binding |
| locX `@+0x18` / locY `@+0x19` | **High** | Misplace stamp |
| Swap `@+0x23` / concat `EBX[0xe]` (`@+0x38`) branch | **High** CF | Stack desync |
| Occupant COID `@+0x28/+0x2c` resolve | **High** CF; field name **Probable** | — |
| Full swap qty / type-6 concat retail | **Probable** | Incomplete stack-merge port |
| Place thiscall ECX=grid at call sites | **Probable** | Decompiler omits; place unit claims thiscall |
| Portable cdecl formals | **Tentative** | Wrong API surface |
| Runtime multi-type / swap / concat | **Open** | — |

---

## 3. Cross-check: dispatch + ABI (sealed)

```text
// Client_PacketDispatch @ 0x00815710 (live decompile 2026-07-29)
case 0x2037:
case 0x203b:
  Client_RecvInventoryDropResponse();  // call 0x008159c2
  return 1;

// Call site bytes @ 0x008159be (read_memory):
//   8B DE          MOV EBX, ESI     ; packet
//   8B C5          MOV EAX, EBP     ; client
//   E8 69 DD FF FF CALL 0x00813730

// Prologue @ 0x00813730 (read_memory):
//   81 EC 94 00 00 00   SUB ESP, 0x94
//   55 56               PUSH EBP / ESI
//   8B F0               MOV ESI, EAX      ; client
//   C6 86 B6 00 00 00 00 MOV BYTE [ESI+0xB6], 0
//   E8 …                CALL FUN_007a69d0
//   81 3B 3B 20 00 00   CMP DWORD [EBX], 0x203B
//   … JE early-out
//   80 7B 22 00         CMP BYTE [EBX+0x22], 0   ; success
```

Same EAX/EBX framing pattern as GrabResponse (`aa_00811be0` call `0x008159b0`). Live body decompile **≡** raw capture.

---

## 4. Surviving contract for AutoCore

```
On S2C DropResponse (dispatch 0x2037; client EAX, packet EBX):
  clear busy(client+0xb6); FUN_007a69d0()
  if opcode==0x203b: return            // shared MM-drop slot; no place
  if !success@+0x22: toast fail; FUN_007fc150; return
  require world/char pointers (client+0xe04 / nested +0xe4e8 / char+0xe98)
  bind grid by inventoryType@+0x1a:
    1 cargo  vehicle+0x2b0
    3 locker char+0xcbc
    5 trade  char+0xce0
    6 other  TFID(char+0xcd8) → +0xce0
    else invalid toast; return
  if swapFlag@+0x23 == 0:
    resolve item (type6: packet TFID@+0x08; else cursor client+0x9b8 vtbl+0x3ac)
    if not already at (locX@+0x18, locY@+0x19): PlaceItemFootprint (FUN_00571620)
    on place fail: toast; never assume server success ⇒ place success
  else if concat@+0x38 == 0:
    swap via occupant COID@+0x28 (FUN_00571010); place packet item
  else:
    concatenate / type-6 merge arms (partially named)
  refresh mission UI; optional UI page host (local_94 → FUN_0085e890)
Never emit type 2 (hardpoint) as DropResponse place path.
Base Write plate: TFID@+8, X/Y/type@+0x18..1a, success@+0x22, swap@+0x23.
Stack-merge parity needs occupant@+0x28 + concat@+0x38 (not in AutoCore Write yet).
```

---

## 5. Open questions

1. Full swap qty accounting and type-6 concat vfunc sequence (not bit-exact / product-named).
2. Place thiscall: recover ECX=grid at both `FUN_00571620` call sites (place unit claims thiscall; DropResponse decompile omits).
3. AutoCore Write omits occupant `@+0x28` / concat `@+0x38` — required if stack-merge is live.
4. Runtime cargo + locker + trade + swap + concat captures; differential open.
5. Product names for `FUN_007a69d0`, `FUN_007fc150`, `FUN_007fc270`, `FUN_0092ce90`, `FUN_0085e890`, `FUN_00571b60`, `FUN_00571b80`, `FUN_00571010`.

**Verdict:** CF map + opcode dispatch + register ABI safe for port of non-swap success path. Do **not** claim swap/concat retail seal, place-ECX bit-exact, or runtime/diff complete. Prior skeptical “opcode Tentative” is **closed**.

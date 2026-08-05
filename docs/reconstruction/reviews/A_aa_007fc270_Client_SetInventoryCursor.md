# Review A (reconstruction fidelity): `aa_007fc270` Client_SetInventoryCursor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc270` |
| **VA** | `0x007fc270` |
| **Canonical name** | `Client_SetInventoryCursor` (**INFERRED**) |
| **Aliases** | `FUN_007fc270`, `Named_CalleeOf_Client_RecvInventoryEquip_007fc270` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007fc270_Client_SetInventoryCursor.md` |
| **System** | `inventory-transfer` (UI / cursor) |
| **Evidence pass** | Live Ghidra decompile + `read_memory`; pair with clear `0x007fc150` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Client inventory cursor show / bind path** (inverse of clear):

1. Gate: **EDI != 0** (decompiler `unaff_EDI`; likely item/cursor-payload non-null from parent).
2. `FUN_0051f4e0()` with client-related ECX from `client+0xe98` path (prep).
3. If cursor root `**(client+0xf40)` → vfunc **`+0xa8( client+0x9b8 )`** (attach/show).
4. `*(cursor+0x494) = param_1` (held payload / item id / flags — **set**, not clear).
5. Cursor vfunc **`+0x3b0`**, then **`+0x3bc(4)`**, size query **`+0x140`**, position using `client+0x302c/+0x3030` centered, place via **`+0x11c`**.
6. If `client+0x1168` → vfunc **`+4(0)`** (re-open / unhide sibling UI vs clear’s `(1)`).

**ESI = client\***. Stack arg0 = value written to cursor `+0x494`.

Used by `Client_RecvInventoryEquip` when put-in-hand / cursor should display the equipped-from item; also drop/grab UI.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fc270_FUN_007fc270.md` |
| Annotated | `docs/reconstruction/raw/aa_007fc270_FUN_007fc270.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fc270.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fc270_FUN_007fc270.md` |
| Counterpart B | `reviews/B_aa_007fc270_Client_SetInventoryCursor.md` |

---

## 3. Signature

```c
// ESI = Client*; EDI = non-null gate; stack arg0 → cursor[+0x494]
void Client_SetInventoryCursor(undefined4 cursorPayload /* stack */);
```

### Image notes (`read_memory` 2026-07-29)

```
sub esp, 0x10
test edi, edi
jz  exit
; FUN_0051f4e0 via ecx from [esi+0xe98]
; optional root vfunc +0xa8(cursor)
mov edx, [esp+0x14]          ; stack payload after prologue
mov [ *(esi+0x9b8) + 0x494 ], edx
; show/size/position vfuncs on cursor
; optional [esi+0x1168].vfunc+4(0)
```

| Stage | Match | Confidence |
|---|---|---|
| EDI null gate | **Yes** | **High** |
| Cursor `+0x494 = param` | **Yes** | **High** |
| Show/position vfuncs | **Yes** | **Medium** product |
| Symmetric to clear (`+0x494=0`, `+0x3b0(0)`) | **Yes** | **High** |
| ESI client | **High** | `[esi+…]` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Cursor set / show | **High** | equip residual pairing |
| Payload → `+0x494` | **High** | store |
| Position uses `+0x302c/+0x3030` | **High** CF | screen center-ish |
| EDI source (item*?) | **Tentative** | only non-zero gate known |
| Payload type (TFID vs flags vs ptr) | **Open** | width dword only |

---

## 5. Gaps / open

1. Exact type of stack payload / EDI gate object.
2. Cursor widget class product name.

**Verdict:** **accept-with-gaps**

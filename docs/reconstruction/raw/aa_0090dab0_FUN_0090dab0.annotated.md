# Annotated low-level: FUN_0090dab0 → Client_Input_DismissUiWindowTable5_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0090dab0` |
| VA | `0x0090dab0`–`0x0090dad5` (**38 B**) |
| System | input-drive-control |
| Date | 2026-08-05 (MEGA-097 refresh) |
| Canonical name | `Client_Input_DismissUiWindowTable5_Inferred` |
| Ghidra name | `FUN_0090dab0` |

---

## Machine-level notes

- Source: raw capture + MEGA-097 live re-verify (disasm + call sites authority).
- **ABI:** custom **EAX = client host** (not ECX thiscall). Bare `RET`. Saves EBX/ESI/EDI.
- **CF:** fixed 5-iteration pointer walk over `DAT_00d09a38`..`<0xd09a4c`; each slot → `FUN_0090d400` with ESI=slot, EDI=host.
- Decompiler shows `void`/`puVar1++` only — **does not** surface EAX→EDI or ESI load; do not port from decompile alone.
- Parent ESC path: after `FUN_0090d390` finds any active table window, reload `EAX=EBX` (host) and call this unit.
- Table is five global UI window* slots (init sizes 0x554/0x5d8/0x604/0x54c/0x588 via `FUN_0093e7e0`).
- Callee dismiss path (evidence): window vtbl `+0x3d8` gate → `+0xcc(0)` + `+0x440`; host `+0xb0(window)`, optional `+0x3bc(DAT_00d1b978)`, `+0x3f4(-1)`.

---

## Pseudocode (annotated; ABI restored)

```c
// EAX = client host* (custom register this). Bare RET.
// Walks DAT_00d09a38[5] and dismisses each active UI window via FUN_0090d400.
void Client_Input_DismissUiWindowTable5_Inferred(void /* host in EAX */)
{
  undefined4 *slot;   // EBX
  // EDI = EAX (host) — sealed by 8B F8; omitted by decompiler
  // ESI = *slot before each CALL FUN_0090d400

  slot = &DAT_00d09a38;
  do {
    FUN_0090d400();   // uses ESI=*slot, EDI=host
    slot = slot + 1;  // +4 bytes
  } while ((int)slot < 0xd09a4c);
  return;
}
```

---

## Control flow

```text
entry:
  save EBX/ESI/EDI
  EDI = EAX (host)
  EBX = &DAT_00d09a38
loop:
  ESI = *EBX
  CALL FUN_0090d400
  EBX += 4
  if EBX < 0xd09a4c goto loop
  restore; RET
```

---

## Call graph (OWN VA only dualled)

```text
Client_Input_OnKeyDown_MatchAction  0x00911030
  ESC + flag+0x50d clear:
    FUN_0090d390  → any active table window?
    yes: MOV EAX,EBX; CALL FUN_0090dab0  [OWN MEGA-097]
           └─ FUN_0090d400 ×5  (dismiss-if-active; not dualled here)
```

---

## Open questions / gaps

- Product English names for the five UI window types at `DAT_00d09a38`..`48`.
- Product names for vtbl slots `+0x3d8` / `+0xcc` / `+0x440` / host `+0xb0` / `+0x3bc` / `+0x3f4`.
- Exact role of second call site `0x00911893` (same parent image; not expanded in decompile body — bytes seal `MOV EAX,EBX; CALL`).
- Runtime / bit-exact / differential — open (terminal false).

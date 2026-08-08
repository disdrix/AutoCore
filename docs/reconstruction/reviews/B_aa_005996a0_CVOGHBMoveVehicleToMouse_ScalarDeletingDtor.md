# Review B (skeptical / adversarial): `aa_005996a0` CVOGHBMoveVehicleToMouse_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005996a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY **R12-028**) |
| **Counterpart** | `reviews/A_aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs/callers/callees. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a vector-deleting dtor (flags&2 / count) | **Falsified** — only bit0 tested; no count arg; body 30 B |
| 2 | operator_delete never returns / function diverges | **Falsified** — bytes always `MOV EAX,ESI; RET 4`; `ADD ESP,4` after delete |
| 3 | Complete is inline / no callee | **Falsified** — `CALL 0x00599570` |
| 4 | CODE call sites exist | **Falsified** — DATA xref only (vtbl[0]); callers list empty |
| 5 | Same unit as complete `00599570` | **Falsified** — body has no flags/free; scalar shell does |
| 6 | Same as base MoveVehicle vtbl[0] `00636d10` | **Falsified** — `009e3b70` dword0 = `00636d10` ≠ this VA; complete callees differ (`00636b90` vs `00599570`) |
| 7 | Product name unsealed / needs `_Inferred` | **Falsified** — RTTI `.?AVCVOGHBMoveVehicleToMouse@@` @ `0x00af33e0` |
| 8 | `RET 0` / cdecl / stack `this` | **Falsified** — `MOV ESI,ECX`; `C2 04 00` |
| 9 | This is OnEnd / OnHeartBeat / mouse aim logic | **Falsified** — no steer/mouse math; pure dtor shell |
| 10 | Same as `CVOGHBBase_ScalarDeletingDtor` `00508630` | **Falsified** — different body (base free path has list detach); this shell only chains ToMouse complete |
| 11 | Runtime Confirmed | **Fails** — open (no Launcher); never claimed |
| 12 | Hex identity with MoveVehicle scalar | **Falsified** — same CF shape, different complete rel32 (`C8FEFFFF`→`00599570` vs `78FEFFFF`→`00636b90`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this / RET 4 / return this | **High** | Wrong delete path |
| flags bit0 → delete | **High** | Leak or double-free port |
| vtbl[0] @ `009d5590` | **High** | Wrong slot binding |
| Complete `00599570` first | **High** | Incomplete teardown if skipped |
| Product demangle CVOGHBMoveVehicleToMouse | **High** | Naming only if wrong |
| Not base MoveVehicle dword0 | **High** | Wrong subclass free shell |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
push esi
mov esi, ecx
call FUN_00599570          ; ToMouse complete/body
test byte [esp+8], 1
jz skip
push esi
call operator_delete
add esp, 4
skip:
mov eax, esi
pop esi
ret 4
```

Hex (30 B): `568bf1e8c8fefffff644240801740956e86d01efff83c4048bc65ec20400`

Vtbl dword0 @ `0x009d5590` = `0x005996a0`. RTTI name `.?AVCVOGHBMoveVehicleToMouse@@`.

Reject ports that:

- Invent vector-deleting (element count / bit2).
- Skip complete `00599570` before free.
- Treat this as OnEnd / OnHeartBeat / mouse aim.
- Bind MoveVehicle vtbl[0] to this VA (or vice versa).
- Claim `operator_delete` diverges (omit return this).
- Claim runtime Confirmed without CE/Launcher.
- Merge with base scalar `00636d10` or base family `00508630` body.

---

## 4. Surviving contract for AutoCore

```csharp
// void* ScalarDeletingDtor(this, byte flags)  // thiscall, ret 4
// FUN_00599570(this); if ((flags&1)!=0) delete this; return this;
```

Port as MSVC vtbl[0] scalar dtor for **CVOGHBMoveVehicleToMouse**. Pair complete body `00599570` (residual). Keep distinct from:

- `CVOGHBMoveVehicle_ScalarDeletingDtor` `00636d10` (parent dual)
- `CVOGHBBase_ScalarDeletingDtor` `00508630`
- Shared OnEnd `00636ba0` / OnHeartBeat `00636cc0`

---

## 5. Verdict

**accept** — adversarial checks confirm standard scalar-deleting dtor with RTTI-sealed product name. Residual: complete body dual, runtime. Not reject. **Never Runtime Confirmed.**

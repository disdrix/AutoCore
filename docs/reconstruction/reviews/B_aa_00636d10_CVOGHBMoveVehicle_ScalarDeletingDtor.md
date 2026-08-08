# Review B (skeptical / adversarial): `aa_00636d10` CVOGHBMoveVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636d10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY **R11-024**) |
| **Counterpart** | `reviews/A_aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs/callers/callees. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a vector-deleting dtor (flags&2 / count) | **Falsified** — only bit0 tested; no count arg; body 30 B |
| 2 | operator_delete never returns / function diverges | **Falsified** — bytes always `MOV EAX,ESI; RET 4`; `ADD ESP,4` after delete |
| 3 | Complete is inline / no callee | **Falsified** — `CALL 0x00636b90` |
| 4 | CODE call sites exist | **Falsified** — DATA xref only (vtbl[0]); callers list empty |
| 5 | Same unit as complete `00636b90` | **Falsified** — body has no flags/free; scalar shell does |
| 6 | Shared with ToMouse vtbl[0] | **Falsified** — `009d5590` dword0 = `005996a0` ≠ this VA |
| 7 | Product name unsealed / needs `_Inferred` | **Falsified** — RTTI `.?AVCVOGHBMoveVehicle@@` @ `0x00af33c0` |
| 8 | `RET 0` / cdecl / stack `this` | **Falsified** — `MOV ESI,ECX`; `C2 04 00` |
| 9 | This is OnEnd / fire / axis park | **Falsified** — no SetSteer/Push; pure dtor shell |
| 10 | Same as `CVOGHBBase_ScalarDeletingDtor` `00508630` | **Falsified** — different body (base free path has list detach); this shell only chains MoveVehicle complete |
| 11 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this / RET 4 / return this | **High** | Wrong delete path |
| flags bit0 → delete | **High** | Leak or double-free port |
| vtbl[0] @ `009e3b70` | **High** | Wrong slot binding |
| Complete `00636b90` first | **High** | Incomplete teardown if skipped |
| Product demangle CVOGHBMoveVehicle | **High** | Naming only if wrong |
| Not ToMouse dword0 | **High** | Wrong subclass free shell |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
push esi
mov esi, ecx
call FUN_00636b90          ; complete/body
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

Hex (30 B): `568bf1e878fefffff644240801740956e8fd2ae5ff83c4048bc65ec20400`

Vtbl dword0 @ `0x009e3b70` = `0x00636d10`. RTTI name `.?AVCVOGHBMoveVehicle@@`.

Reject ports that:

- Invent vector-deleting (element count / bit2).
- Skip complete `00636b90` before free.
- Treat this as OnEnd / steer park.
- Bind ToMouse vtbl[0] to this VA.
- Claim `operator_delete` diverges (omit return this).
- Claim runtime Confirmed without CE/Launcher.
- Merge with base scalar `00508630` body.

---

## 4. Surviving contract for AutoCore

```csharp
// void* ScalarDeletingDtor(this, byte flags)  // thiscall, ret 4
// FUN_00636b90(this); if ((flags&1)!=0) delete this; return this;
```

Port as MSVC vtbl[0] scalar dtor for **CVOGHBMoveVehicle**. Pair complete body `00636b90` (residual). Keep distinct from:

- `CVOGHBBase_ScalarDeletingDtor` `00508630`
- ToMouse scalar shell `005996a0`
- OnEnd `00636ba0` / fire `00636cc0`

---

## 5. Verdict

**accept** — adversarial checks confirm standard scalar-deleting dtor with RTTI-sealed product name. Residual: complete body dual, runtime. Not reject.

# Review A (reconstruction fidelity): `aa_005d4fd0` Object_UnloadGraphics_Entry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4fd0` |
| **VA** | `0x005d4fd0`–`0x005d5025` exclusive (**85 B** / `0x55`) |
| **Canonical name** | `Object_UnloadGraphics_Entry_Inferred` (Ghidra `FUN_005d4fd0`) |
| **Review date** | `2026-08-04` (W37-AB) |
| **Reviewer role** | Reconstruction fidelity (logged unload-graphics entry) |
| **Counterpart** | `reviews/B_aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md` |
| **System** | client / object graphics lifecycle |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: W31-T `Object_UnloadGraphics_Inferred` (`0x005825d0`).

---

## 1. Purpose

**Vtable-installed logged entry** for unload-graphics:

1. Resolve name id from optional record (`root+0x6c` path → `+0x34`, else `-1`).
2. Root `vtbl+0x160(nameId)` → log argument.
3. `FUN_007a4480(-1, "UnloadGraphics on %s (%d)", arg)`.
4. `Object_UnloadGraphics_Inferred(self)` (W31-T core).
5. **Tail JMP** to base `vtbl+4` with `this = self-0x40`.

Not a full object delete; does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AB) | `docs/reconstruction/raw/aa_005d4fd0_FUN_005d4fd0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d4fd0_FUN_005d4fd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_UnloadGraphics_Entry_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d4fd0.cpp` |
| Function records | `functions/aa_005d4fd0_FUN_005d4fd0.md`, `functions/aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; 85 B hex; 8 DATA xrefs; 0 CODE callers |
| Core | W31-T `Object_UnloadGraphics_Inferred` (sole CODE callee relationship inverse) |
| String | `read_memory` @ `0x009dac54` → `UnloadGraphics on %s (%d)` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, unowned VA edits.

---

## 3. Signature

```c
// __thiscall; ECX = MI object*; void; ends in tail JMP (no bare RET)
void __fastcall Object_UnloadGraphics_Entry_Inferred(void* mi_this);
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX` throughout |
| Log string | imm `0x009dac54` |
| Core call | rel `E8` → `0x005825d0` with `MOV ECX,ESI` |
| Epilogue | `LEA ECX,[ESI-0x40]; POP ESI; JMP [EAX+4]` (`FF 60 04`) |
| Body range | entry `005d4fd0`, exclusive end `005d5025` |
| Xrefs | **8** DATA (vtable) |

---

## 4. Control flow (sealed)

```
ESI = this
nameRec = *(vbtable-root path + 0x6c)
nameId = nameRec ? *(nameRec+0x34) : -1
arg = root.vtbl+0x160(nameId)
FUN_007a4480(-1, "UnloadGraphics on %s (%d)", arg)
FUN_005825d0(this)
JMP base.vtbl+4 with this = this-0x40
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| Null name → -1 | **Yes** — `83 C8 FF` / `8B 40 34` |
| vcall +0x160 | **Yes** — `FF 92 60 01 00 00` |
| Log format imm | **Yes** — `68 54 AC 9D 00` |
| Core UnloadGraphics | **Yes** — rel to `005825d0` |
| Tail not RET | **Yes** — `FF 60 04` (decompiler “call” warning residual on form only) |
| ADD ESP,0x10 after log | **Yes** — cleans leftover vcall push + 3 log args |

---

## 5. Machine bytes (`read_memory` @ `0x005d4fd0`, 85 B)

Hex:  
`568bf18b46c48b48048d4431c48b80a800000085c0750583c8ffeb038b40348b56c48b4a048b5431c48d4c31c450ff9260010000506854ac9d006affe86ff41c0083c4108bcee8b5d5faff8b46c08d4ec05eff6004`

---

## 6. Callers / callees

| Callee | Role |
|--------|------|
| root `vtbl+0x160` | name resolve for log |
| `FUN_007a4480` | levelled log |
| `FUN_005825d0` | unload-graphics core (W31-T) |
| base `vtbl+4` | tail chain |

| Xref kind | Count / sites |
|-----------|----------------|
| CODE | 0 |
| DATA | 8 — `009ce7e0`, `009ceb30`, `009d4c90`, `009da6d8`, `009db8f0`, `009cbe40`, `009cd748`, `009cfd60` |

---

## 7. Gaps

- Format `%s (%d)` vs single intentional vararg (bytes) — second conversion residual.
- Product English for `vtbl+0x160`, name record layout, tail base method.
- Full class atlas for 8 vtable installs.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Entry CF, string, core call, DATA-only dispatch, and **tail JMP** **sealed**. Format-arg residual + product English open → **accept-with-gaps**.

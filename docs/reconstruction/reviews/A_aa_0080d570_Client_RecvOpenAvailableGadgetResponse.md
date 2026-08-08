# Review A (reconstruction fidelity): `aa_0080d570` Client_RecvOpenAvailableGadgetResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080d570` |
| **VA** | `0x0080d570` |
| **Body** | `0x0080d570`–`0x0080d915` (933 bytes) |
| **Canonical name** | `Client_RecvOpenAvailableGadgetResponse` (Ghidra `FUN_0080d570`) |
| **Review date** | `2026-08-04` (WQ8R-G dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + bulk xrefs + dispatch decompile. **No** `disassemble_bytes`.

---

## 1. Purpose

S2C **`0x20A8` OpenAvailableGadgetResponse** handler: resolve target inventory item + tinkering kit, apply success (open-slot increment + success toast/SFX) or failure (reason enum 1–4, optional catastrophic item destroy), then attempt kit removal and refresh inventory/mission UI windows.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0080d570_FUN_0080d570.md` |
| Annotated | `docs/reconstruction/raw/aa_0080d570_FUN_0080d570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvOpenAvailableGadgetResponse.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0080d570.cpp` |
| Function record | `docs/reconstruction/functions/aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` |
| Dispatch clean | `reconstructed-exact/Client_PacketDispatch.cpp` case `0x20a8` |
| Live decompile | ≡ raw 2026-07-23 CF |
| Entry bytes | `read_memory` 256 B @ `0x0080d570`; epilogue @ `0x0080d900` |
| Related duals | FindItemByCoid, ContainsItem, RemoveItem |

**Not performed:** `disassemble_bytes`, Launcher, live packet capture, bit-exact.

---

## 3. Sealed facts

| Claim | Confidence | Evidence |
|---|---|---|
| Opcode **`0x20A8`** | **Confirmed** | `Client_PacketDispatch` case + call `0x00815d1e` |
| Sole static caller = dispatch | **Confirmed** | xref_count 1 |
| `RET 4` + frame `0x104` | **Confirmed** | epilogue `81 C4 04 01 00 00 C2 04 00` |
| ESI = client context | **High** | entry `MOV EAX,[ESI+0xE98]`; pattern shared with other S2C handlers |
| Early gate char + cargo host | **High** | decompile + entry bytes |
| Cargo then locker Find | **Confirmed** | this = `*(*(char)+0x250)+0x2B0` else `char+0xCBC` |
| Packet COID `@+0x10/14`, kit id `@+0x18/1c` | **High** | decompile + entry loads |
| Success `@+0x2c`, reason `@+0x28`, cat `@+0x2d` | **High** | `CMP [EBP+0x2C]`; switch on `[EBP+0x28]` |
| Fail reasons 1–4 product strings | **High** | embedded strings |
| Kit cast vtbl `+0x200` | **High** | decompile |
| SFX keys `tinker_success` / `tinker_fail` | **Confirmed** | strings + audio table calls |
| `DAT_00a7d1f0` = `"of"` | **Confirmed** | `read_memory` |
| Post-path kit remove + UI refresh | **High** | Contains/Remove + `FUN_00933310` + `Client_RefreshOpenMissionUiWindows` |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Char / cargo-host gates | **Yes** |
| Dual-grid FindItemByCoid | **Yes** (asm this restored in clean/annotated) |
| Resolve kit + cast | **Yes** |
| Success open-slot++ / toast / SFX | **Yes** |
| Fail switch 1–4 + catastrophic | **Yes** |
| Shared kit cleanup + refresh | **Yes** |
| Live decompile ≡ raw | **Yes** |

---

## 5. Gaps

1. Kit inventory host MI expression for final RemoveItem — decompiler form residual.
2. Success sprintf vararg packing incomplete in decompiler.
3. Full packet size / unused fields.
4. Runtime / bit-exact open.
5. Whether open-slot counter is purely client presentation vs mirrored server state.

---

## 6. Verdict

**accept-with-gaps** — wire identity, dual-grid resolve, success/fail CF, and product fail enum sealed; nested kit-host and sprintf packing residual.

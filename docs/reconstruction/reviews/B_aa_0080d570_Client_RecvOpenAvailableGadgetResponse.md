# Review B (skeptical / adversarial): `aa_0080d570` Client_RecvOpenAvailableGadgetResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080d570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** on opcode/CF/grids; **reject** “decompiler Find this is complete”, “full kit layout sealed”, bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Two FindItemByCoid calls are identical (same this) | **Falsified** — bytes use cargo `+0x2B0` then locker `+0xCBC` |
| 2 | Handler is generic inventory drop/add | **Falsified** — tinker/gadget strings + 0x20A8 OpenAvailableGadgetResponse |
| 3 | `unaff_ESI` is junk | **Falsified** — ESI is dispatch client context (`+0xe98` character) |
| 4 | Success always destroys kit immediately in success branch | **Fail as identity** — kit remove is **shared post** path; success mainly increments open slots + toast |
| 5 | Fail reason 4 always destroys item | **Falsified** — only when `pkt[+0x2d]` catastrophic; else soft fail string |
| 6 | Scaffold string-name is product symbol | **Falsified** — string-derived scaffold; dispatch label is authoritative wire name |
| 7 | Clean twin `FUN_0080d570.cpp` auto-scaffold was dual quality | **Falsified** — replaced 2026-08-04 |
| 8 | Bit-exact / complete kit MI host | **Fail** — residual |
| 9 | Many callers | **Falsified** — sole caller PacketDispatch |

---

## 2. Decisive corrections

```
// Decompiler:
item = Find(coid); if (!item) item = Find(coid);  // same this — WRONG

// Bytes:
item = FindItemByCoid( cargoGrid = *(*(client+0xe98)+0x250)+0x2b0 , coid );
if (!item)
  item = FindItemByCoid( lockerGrid = *(client+0xe98)+0xcbc , coid );
```

Matches sealed DropResponse inventoryType **1** / **3** grid roots.

---

## 3. Residual risks

1. Catastrophic path double-Contains on `item` without explicit grid this in decompiler — may be Contains(item) via wrong this; **Requires** care when porting (follow sealed Contains dual: list/grid membership).
2. sprintf arg order for success toast not fully recovered.
3. No runtime packet capture of 0x20A8.

---

## 4. Verdict

**accept-with-gaps** — adversarial pass elevates dual-grid find and opcode as sealed; keeps kit-host MI, sprintf packing, and runtime open. Agrees with A overall.

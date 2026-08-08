# Review B (skeptical / adversarial): `aa_0093e7e0` Client_UI_CreateNDUIDialogs_InstallHost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093e7e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-133) |
| **Counterpart** | `reviews/A_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function is only **death-respawn button** ctor/helper | **Falsified** — dozens of `operator_new` installs; plates for cursor, title/action, tooltip, death suite, HUD, information, arena; death XML is one site at `host+0x1158` |
| 2 | Same as parent `FUN_0094a580` / entire InitUserInterface | **Falsified** — parent owns input-device init, connect switch, other calls; this unit is the createNDUIDialogs **body** only (`CALL` after log) |
| 3 | **thiscall** ECX = host | **Falsified** — prologue loads host from **stack** into EBP; epilogue **`RET 4`**; ECX used only for nested thiscalls |
| 4 | **cdecl** (caller cleans) | **Falsified** — `C2 04 00` |
| 5 | Mission-only / no general UI chrome | **Falsified** — cursor, inventory item, tooltip, chat bg, HUD plates |
| 6 | Returns status / bool | **Falsified** — void; parent ignores return; no EAX success path |
| 7 | `FUN_00931570` is optional debug only | **Falsify attempt fails** — always called with `"winpos.ini"` after install; applies layout to `host+0x1030` table (fopen/fscanf path in its body) |
| 8 | Scaffold `Named_CalleeOf_*` is final name | **Falsified** — plate + role support CreateNDUIDialogs install naming |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 10 | All dialog ctor English sealed | **Fails** — residual catalog → gaps |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall RET 4 / stack host | **Confirmed** | Stack imbalance / wrong this |
| Sole caller `0094a580` | **Confirmed** | Miss alternate entry |
| CreateNDUIDialogs install role | **High** | Wrong system ownership |
| Phase plate strings | **Confirmed** | Mis-phase docs |
| Post `+0xc6` / winpos coupling | **High** | Layout port bugs |
| Per-dialog product names | **Low** | Wrong AutoCore class map |
| Vtbl slot English | **Low** | Doc only |
| Runtime | **Open** | Behavior drift |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Client_UI_CreateNDUIDialogs_InstallHost_Inferred.cpp

Prologue (disassemble_function):
  0093e7e0  PUSH -1
  0093e7e2  PUSH 0x9bb29b
  … FS:[0] …
  0093e7f5  SUB ESP,0x470
  0093e7fc  MOV EBP,[ESP+0x484]   ; host
  0093e805  PUSH 0xa2d610         ; "@@CreateNDUIDialogs"
  0093e811  CALL FUN_007a4400

Epilogue:
  0093ff14  MOV EAX,0xa2d3d4      ; "winpos.ini"
  0093ff19  MOV ECX,EBP
  0093ff1b  CALL FUN_00931570
  …
  0093ffa1  RET 4

Xref: From 0094a649 in FUN_0094a580 [UNCONDITIONAL_CALL]
Parent: FUN_007a4480(...,"createNDUIDialogs"); FUN_0093e7e0(unaff_ESI);
```

Reject ports that:

- Name this solely as death-respawn / combat UI.
- Use thiscall without stack host / omit RET 4.
- Merge with full InitUserInterface parent.
- Skip winpos.ini post-pass or `+0xc6` flag loops.
- Invent full product dialog names without ctor duals.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: client createNDUIDialogs bulk install (body of InitUserInterface path).
// Managed port sketch — host owns dialog pointer table + globals.

void ClientUiCreateNdUiDialogsInstallHost(ClientUiHost host)
{
    // 1) Timing plate "@@CreateNDUIDialogs"
    // 2) Cursor at host.CursorSlot (+0x1168): load i_g_2d_cursor.xml; rebind resource
    // 3) For each dialog family: new T(); store host.Slots[i] or static globals
    // 4) Death respawn button: load i_g_2d_btn_death_respawn.xml; set id 0x4e5d
    // 5) For i in 0..0x39: if slot[i] != null) slot[i].PostInstall(i - 0x3a) // vtbl+0x174
    // 6) Pair-flag dialog+0xC6 = true (0x1d pairs); exception host.Slot0x1100 = false
    // 7) ApplyWinPosIni(host, "winpos.ini")  // FUN_00931570
    // 8) Debug timing OutputDebugStringA
}
// ABI: stdcall, 1 pointer arg, void.
```

---

## 5. Verdict

Adversarial pass confirms A's CF/ABI/caller/role. Residual product catalog and vtbl English prevent full **accept** → **accept-with-gaps**.

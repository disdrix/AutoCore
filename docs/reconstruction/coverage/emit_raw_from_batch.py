"""Emit immutable raw captures from a Ghidra batch_decompile JSON map."""
from __future__ import annotations

import json
import re
import sys
from datetime import date
from pathlib import Path

NAMES = {
    "0x004f5650": "VehicleEntity_SetLongitudinalInput",
    "0x004f3620": "VehicleEntity_SetHandbrake",
    "0x004fbc10": "VehicleEntity_PushDriveAxesToController",
    "0x00860e20": "Client_SendInventoryGrab_FromGrid",
    "0x00860a50": "Client_UI_InventoryDropToGrid",
    "0x00813730": "Client_RecvInventoryDropResponse",
    "0x00811be0": "Client_RecvInventoryGrabResponse",
    "0x008151a0": "Client_RecvInventoryAddItem",
    "0x00813f40": "Client_RecvInventoryEquip",
    "0x00813bf0": "Client_RecvInventoryUnequipNotify",
    "0x00571620": "InventoryGrid_PlaceItemFootprint",
    "0x005713a0": "InventoryGrid_FindFreeSlot",
    "0x00570720": "InventoryGrid_AllocateCellArray_Inferred",
    "0x004f3a30": "Vehicle_CreateCargoInventoryFromPageCount",
    "0x00572650": "InventoryGrid_ctor_Inferred",
    "0x005327c0": "CVOGReaction_GiveMission",
    "0x00531b00": "CVOGMission_AddActiveObjective",
    "0x00532b60": "CVOGCharacter_SearchAutoMissions",
    "0x00536540": "CVOGCharacter_CheckMissionPrerequisites",
    "0x005462b0": "CVOGCharacter_CheckMissionRequirements",
    "0x00536080": "CVOGCharacter_CompleteMissionObjectives",
    "0x00534920": "CVOGCharacter_EvaluatePendingObjectives",
    "0x0052aa20": "CVOGCharacter_HasCompletedMission",
    "0x0052da30": "CVOGReaction_FailMission",
    "0x00809460": "Client_RecvObjectiveState",
    "0x00815070": "Client_RecvNpcMissionDialog",
    "0x008ae7c0": "Client_MissionDialogHandleButton",
    "0x008ae130": "Client_UpdateMissionJournal",
    "0x00941590": "Client_RequestCastSkill",
    "0x009418e0": "Client_CastSkillFromQuickBarSlot",
    "0x00921b50": "Client_QuickBarActivateSkillSlot",
    "0x0051a790": "Skill_LocalCastValidate",
    "0x0054c570": "CVOGReaction_ResolveSkillTargets",
    "0x0058d330": "Skill_GatherTargetsInArea",
    "0x00553650": "Skill_ValidateTargetForSkill",
    "0x004d09a0": "CVOGReaction_CastSkillOnTarget",
    "0x005312c0": "CVOGCharacter_AddSkillPoints",
    "0x005208c0": "CVOGCharacter_SetQuickBarSkill",
    "0x00811170": "Client_RecvSkillStatusEffect",
    "0x0051aa00": "Skill_ApplyStatusEffectLocal",
}

SYSTEMS = {
    "0x004f5650": "input-drive-control",
    "0x004f3620": "input-drive-control",
    "0x004fbc10": "input-drive-control",
    "0x00860e20": "inventory-transfer",
    "0x00860a50": "inventory-transfer",
    "0x00813730": "inventory-transfer",
    "0x00811be0": "inventory-transfer",
    "0x008151a0": "inventory-transfer",
    "0x00813f40": "inventory-transfer",
    "0x00813bf0": "inventory-transfer",
    "0x00571620": "inventory-transfer",
    "0x005713a0": "inventory-transfer",
    "0x00570720": "inventory-transfer",
    "0x004f3a30": "inventory-transfer",
    "0x00572650": "inventory-transfer",
    "0x005327c0": "missions-progression",
    "0x00531b00": "missions-progression",
    "0x00532b60": "missions-progression",
    "0x00536540": "missions-progression",
    "0x005462b0": "missions-progression",
    "0x00536080": "missions-progression",
    "0x00534920": "missions-progression",
    "0x0052aa20": "missions-progression",
    "0x0052da30": "missions-progression",
    "0x00809460": "missions-progression",
    "0x00815070": "missions-progression",
    "0x008ae7c0": "missions-progression",
    "0x008ae130": "missions-progression",
    "0x00941590": "skills-abilities",
    "0x009418e0": "skills-abilities",
    "0x00921b50": "skills-abilities",
    "0x0051a790": "skills-abilities",
    "0x0054c570": "skills-abilities",
    "0x0058d330": "skills-abilities",
    "0x00553650": "skills-abilities",
    "0x004d09a0": "skills-abilities",
    "0x005312c0": "skills-abilities",
    "0x005208c0": "skills-abilities",
    "0x00811170": "skills-abilities",
    "0x0051aa00": "skills-abilities",
}

SIG_RE = re.compile(
    r"(?:void|undefined4|undefined1|undefined|int|char|bool|float|uint|"
    r"byte|short|long|double)\s+"
    r"(?:__thiscall\s+|__fastcall\s+|__cdecl\s+|__stdcall\s+)?"
    r"(\w+)\s*\(",
    re.I,
)


def norm_addr(addr: str) -> str:
    a = addr.lower().replace("0x", "")
    return a.zfill(8)


def main() -> int:
    if len(sys.argv) < 2:
        print("usage: emit_raw_from_batch.py <batch.json>")
        return 2
    batch_path = Path(sys.argv[1])
    batch = json.loads(batch_path.read_text(encoding="utf-8"))
    root = Path("docs/reconstruction")
    raw_dir = root / "raw"
    raw_dir.mkdir(parents=True, exist_ok=True)
    written = []
    for addr, code in batch.items():
        hexpart = norm_addr(addr)
        key = f"0x{hexpart}"
        # also try without leading zeros variants in NAMES
        name = NAMES.get(addr.lower()) or NAMES.get(key)
        if not name:
            m = SIG_RE.search(code)
            name = m.group(1) if m else f"FUN_{hexpart}"
        m = SIG_RE.search(code)
        if m and not name.startswith("FUN_"):
            # prefer decompiler symbol when present
            name = m.group(1) if m.group(1) not in ("if", "while", "switch") else name
        elif m and name.startswith("FUN_"):
            name = m.group(1)
        # Prefer map name when FUN_
        if key in NAMES:
            name = NAMES[key]
        elif addr.lower() in NAMES:
            name = NAMES[addr.lower()]
        stable = f"aa_{hexpart}"
        fname = f"{stable}_{name}.md"
        path = raw_dir / fname
        if path.exists():
            # do not overwrite existing raw
            written.append(
                {
                    "stable": stable,
                    "name": name,
                    "addr": key,
                    "system": SYSTEMS.get(addr.lower(), SYSTEMS.get(key, "unknown")),
                    "raw": str(path).replace("\\", "/"),
                    "skipped_existing": True,
                }
            )
            continue
        sysname = SYSTEMS.get(addr.lower(), SYSTEMS.get(key, "unknown"))
        body = (
            f"# Raw capture: {name}\n\n"
            f"| Field | Value |\n"
            f"|---|---|\n"
            f"| **Stable ID** | `{stable}` |\n"
            f"| **Module** | `autoassault.exe` |\n"
            f"| **Image base** | `0x400000` |\n"
            f"| **VA** | `{key}` |\n"
            f"| **Canonical name** | `{name}` |\n"
            f"| **System** | {sysname} |\n"
            f"| **Capture timestamp** | `{date.today().isoformat()}` |\n"
            f"| **Tool** | Ghidra MCP `batch_decompile` |\n"
            f"| **Integrity** | Do not overwrite this raw body; append versioned sections only |\n\n"
            f"---\n\n"
            f"## Raw pseudocode (authoritative decompile)\n\n"
            f"```c\n{code.strip()}\n```\n"
        )
        path.write_text(body, encoding="utf-8")
        written.append(
            {
                "stable": stable,
                "name": name,
                "addr": key,
                "system": sysname,
                "raw": str(path).replace("\\", "/"),
                "skipped_existing": False,
            }
        )
    out = root / "coverage" / "agent_assignments_batch1.json"
    out.write_text(json.dumps(written, indent=2), encoding="utf-8")
    print(f"wrote/kept {len(written)} units -> {out}")
    for w in written:
        print(w["stable"], w["name"], w["system"], "skip" if w["skipped_existing"] else "new")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
